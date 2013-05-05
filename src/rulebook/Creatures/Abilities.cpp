//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-20
// Author:      Juho Lepisto
//
// Filename:    Abilities.cpp
// Description: This is a ability score class that provides the basic ability scores and score
//              modifiers.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "Abilities.h"

// 2. Local enums, constants and macross


// 3. Local global data structs and variables


// 4. Constructor and destructor

Abilities::Abilities(void)
{
  for(int i = strength; i < ability_array_size; i++)
  {
    abilities[i].score = 10;
    abilities[i].tempAdjustment = 0;
    abilities[i].tempModifier = 0;
  }
  return;
}

Abilities::Abilities(const int abilityArray[])
{
  if(abilityArray != 0)
  {
    for(int i = strength; i < ability_array_size; i++)
    {
      if(abilityArray[i] >= 0)
      {
        abilities[i].score = abilityArray[i];
        abilities[i].tempAdjustment = 0;
        abilities[i].tempModifier = 0;
      }
      else
      {
        throw ErrorInvalidData();
      }
    }
  }
  else
  {
    throw ErrorNullPointer();
  }
  return;
}

Abilities::~Abilities(void)
{
  return;
}

// 5. Public functions

void Abilities::setScore(ability_type type, int score)
{
  if(score >= strength)
  {
    abilities[type].score = score;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

unsigned int Abilities::getScore(ability_type type) const
{
  return abilities[type].score;
}

int Abilities::getModifier(ability_type type) const
{
  int tempMod = (abilities[type].score - 10) / 3;
  return tempMod;
}

unsigned int Abilities::getTotalScore(ability_type type) const
{
  int totalScore = abilities[type].score + abilities[type].tempAdjustment;
  if(totalScore < 0)
  {
    totalScore = 0;
  }
  return totalScore;
}

int Abilities::getTotalModifier(ability_type type) const
{
  int totalMod = ((abilities[type].score + abilities[type].tempAdjustment - 10) / 3) + abilities[type].tempModifier;
  return totalMod;
}

void Abilities::addTempAdjustment(ability_type type, int value)
{
  abilities[type].tempAdjustment += value;
  return;
}

void Abilities::removeTempAdjustment(ability_type type, int value)
{
  abilities[type].tempAdjustment -= value;
  return;
}

void Abilities::resetTempAdjustment(ability_type type)
{
  abilities[type].tempAdjustment = 0;
  return;
}

void Abilities::addTempModifier(ability_type type, int value)
{
  abilities[type].tempModifier += value;
  return;
}

void Abilities::removeTempModifier(ability_type type, int value)
{
  abilities[type].tempModifier -= value;
  return;
}

void Abilities::resetTempModifier(ability_type type)
{
  abilities[type].tempModifier = 0;
  return;
}

// 6. Protected functions


// 7. Private functions


