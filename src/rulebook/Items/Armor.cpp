//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-29
// Author:      Juho Lepisto
//
// Filename:    Armor.cpp
// Description: This is a class for armor type items.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "Armor.h"

// 2. Local enums, constants and macross


// 3. Local global data structs and variables


// 4. Constructor and destructor

Armor::Armor(item_data_struct& itemInfo, armor_data_struct& armorInfo) :
Item(itemInfo),
type(armorInfo.type),
armorBonus(armorInfo.armorBonus),
damageResistances{armorInfo.damageResistances[piercing_damage],
  armorInfo.damageResistances[bludgeoning_damage],
  armorInfo.damageResistances[slashing_damage],
  armorInfo.damageResistances[laser_damage],
  armorInfo.damageResistances[plasma_damage],
  armorInfo.damageResistances[attunement_damage],
  armorInfo.damageResistances[explosive_damage],
  armorInfo.damageResistances[fire_damage],
  armorInfo.damageResistances[frost_damage],
  armorInfo.damageResistances[chemical_damage],
  armorInfo.damageResistances[radiation_damage],
  armorInfo.damageResistances[electrical_damage]}
{
  armorBonusMod = 0;
  deflectionBonus = 0;
  raceType = armorInfo.raceType;
  for(int i = 0; i < damage_resistance_array_max; i++)
  {
    damageResistanceMods[i] = 0;
  }
  Item::setType(armor_item);
  return;
}

Armor::~Armor(void)
{
  return;
}

// 5. Public functions

void Armor::setArmorBonusMod(int modifier)
{
  armorBonusMod = modifier;
  return;
}

int Armor::getArmorBonus(void) const
{
  int totalBonus = armorBonus + armorBonusMod;
  return totalBonus;
}

void Armor::setDamageResistanceMod(damage_type damageType, int modifier)
{
  if(modifier >= 0)
  {
    if(damageType < damage_resistance_array_max)
    {
      damageResistanceMods[damageType] = modifier;
    }
    else
    {
      throw ErrorArrayOutOfBounds();
    }
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

int Armor::getDamageResistance(damage_type damageType) const
{
  int totalResistance;
  if(damageType < damage_resistance_array_max)
  {
    totalResistance = damageResistances[damageType] + damageResistanceMods[damageType];
  }
  else
  {
    throw ErrorArrayOutOfBounds();
  }
  return totalResistance;
}

void Armor::setDeflectionBonus(int bonus)
{
  deflectionBonus = bonus;
  return;
}

int Armor::getDeflectionBonus(void) const
{
  return deflectionBonus;
}

void Armor::setArmorRaceType(character_race newRace)
{
  raceType = newRace;
  return;
}

character_race Armor::getArmorRaceType(void) const
{
  return raceType;
}

// 6. Protected functions


// 7. Private functions

