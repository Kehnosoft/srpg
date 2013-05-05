//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-29
// Author:      Juho Lepisto
//
// Filename:    BaseSkills.cpp
// Description: This is a base skills class that is common to all creatures, players and
//              enemies alike.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "BaseSkills.h"

// 2. Local enums, constants and macross


// 3. Local global data structs and variables


// 4. Constructor and destructor

BaseSkills::BaseSkills(const Abilities* abilityPointer) : abilities(abilityPointer)
{
  if(abilityPointer != 0)
  {
    for(int i = climbing; i < skill_array_size; i++)
    {
      skills[i].points = 0;
      skills[i].bonus = 0;
      skills[i].tempMod = 0;
    }
    trainedSkills = 0;
  }
  else
  {
    throw ErrorNullPointer();
  }
  return;
}

BaseSkills::~BaseSkills(void)
{
  return;
}

// 5. Public functions

void BaseSkills::increaseSkill(skill_type type, int value)
{
  if(value > 0)
  {
    skills[type].points += value;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void BaseSkills::setSkillPoints(skill_type type, int value)
{
  if(value >= 0)
  {
    skills[type].points = value;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

int BaseSkills::getSkillPoints(skill_type type) const
{
  int totalSkill = skills[type].bonus + skills[type].tempMod;
  totalSkill += abilities->getTotalModifier(skillAbilityMods[type]);
  bf skillFlag = 1UL << type;
  if(skillFlag & trainedSkills)
  {
    totalSkill += skills[type].points * 2;
  }
  else
  {
    totalSkill += skills[type].points;
  }
  return totalSkill;
}

void BaseSkills::increaseSkillBonus(skill_type type, int value)
{
  skills[type].bonus += value;
  return;
}

void BaseSkills::decreaseSkillBonus(skill_type type, int value)
{
  skills[type].bonus -= value;
  return;
}

void BaseSkills::increaseSkillTempMod(skill_type type, int value)
{
  skills[type].tempMod += value;
  return;
}

void BaseSkills::decreaseSkillTempMod(skill_type type, int value)
{
  skills[type].tempMod -= value;
  return;
}

void BaseSkills::setTrainedSkill(bf skills)
{
  if(skills <= max_skill_bit)
  {
    trainedSkills |= skills;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void BaseSkills::removeTrainedSkill(bf skills)
{
  if(skills <= max_skill_bit)
  {
    trainedSkills &= ~skills;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

// 6. Protected functions


// 7. Private functions

