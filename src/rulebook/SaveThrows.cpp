/*
 * SaveThrows.cpp
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#include "Errors.h"
#include "Dice.h"
#include "Abilities.h"
#include "SaveThrows.h"

SaveThrows::SaveThrows(Abilities* statsPointer) : saveDie(1, 20)
{
  stats = statsPointer;

  for(int i = 0; i < saves; i++)
  {
    saveThrowMods[i].base = 0;
    saveThrowMods[i].attunement = 0;
    saveThrowMods[i].miscMod = 0;
    saveThrowMods[i].tempMod = 0;
  }
  return;
}

SaveThrows::~SaveThrows()
{
  return;
}

void SaveThrows::setBase(save_enum type, int base)
{
  if(type < saves)
  {
    saveThrowMods[type].base = base;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void SaveThrows::addAttuneMod(save_enum type, int attuneMod)
{
  if(type < saves)
  {
    saveThrowMods[type].attunement += attuneMod;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void SaveThrows::removeAttuneMod(save_enum type, int attuneMod)
{
  if(type < saves)
  {
    saveThrowMods[type].attunement -= attuneMod;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void SaveThrows::addMiscMod(save_enum type, int miscMod)
{
  if(type < saves)
  {
    saveThrowMods[type].miscMod += miscMod;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void SaveThrows::removeMiscMod(save_enum type, int miscMod)
{
  if(type < saves)
  {
    saveThrowMods[type].miscMod -= miscMod;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void SaveThrows::addTempMod(save_enum type, int tempMod)
{
  if(type < saves)
  {
    saveThrowMods[type].tempMod += tempMod;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void SaveThrows::removeTempMod(save_enum type, int tempMod)
{
  if(type < saves)
  {
    saveThrowMods[type].tempMod -= tempMod;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

int SaveThrows::getSave(save_enum type) const
{
  int saveRoll = 0;
  if(type < saves)
  {
    saveRoll = saveDie.roll();
    saveRoll += saveThrowMods[type].base + saveThrowMods[type].attunement + saveThrowMods[type].miscMod + saveThrowMods[type].tempMod;

    switch(type)
    {
    case fort:
      saveRoll += stats->getModifier(constitution);
      break;

    case reflex:
      saveRoll += stats->getModifier(dexterity);
      break;

    case will:
      saveRoll += stats->getModifier(attunement);
      break;

    default:
      break;
    }
  }
  else
  {
    throw ErrorInvalidData();
  }
  return saveRoll;
}
