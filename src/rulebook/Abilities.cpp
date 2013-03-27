/*
 * Abilities.cpp
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#include "Errors.h"
#include "Abilities.h"

Abilities::Abilities(void)
{
  for(int i = 0; i < max_stats; i++)
  {
    abilities[i].score = 0;
    abilities[i].tempAdjustment = 0;
    abilities[i].tempModifier = 0;
  }
  return;
}

Abilities::~Abilities(void)
{
  return;
}

void Abilities::setScore(ability_type type, int score)
{
  if(score >= 0)
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
  int tempMod = (abilities[type].score - 10) % 3;
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
  int totalMod = ((abilities[type].score - 10) % 3) + abilities[type].tempModifier;
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


