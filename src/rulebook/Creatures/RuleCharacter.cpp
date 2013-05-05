//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-13
// Author:      Juho Lepisto
//
// Filename:    RuleCharacter.cpp
// Description: This is a base class for player characters.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "RuleCharacter.h"

// 2. Local enums, constants and macross

static const int levelGap = 15;
static const int levelingArray[levelGap] = {0,      2000,   5000,   9000,   15000,
                                            23000,  35000,  51000,  75000,  105000,
                                            155000, 220000, 315000, 445000, 635000};

// 3. Local global data structs and variables
                                            
                                            
// 4. Constructor and destructor
                                            
Character::Character(const init_stats initStats, const character_type initType) : Creature(initStats)
{
  experience = 0;
  levelPenalty = 0;
  level = 1;
  return;
}

Character::~Character(void)
{
  return;
}

// 5. Public functions

bool Character::addExperience(int experienceIncrease)
{
  bool levelUp = false;
  if(experienceIncrease > 0)
  {
    experience += experienceIncrease;
    while((experience >= levelingArray[level]) && (level < levelGap))
    {
      levelUp = true;
      level++;
    }
  }
  else
  {
    throw ErrorInvalidData();
  }
  return levelUp;
}

int Character::getExperience(void) const
{
  return experience;
}

void Character::applyLevelPenalty(int penalty)
{
  if(penalty > 0)
  {
    levelPenalty = penalty;
  }
  else
  {
    throw ErrorInvalidData();
  }
}

void Character::removeLevelPenalty(void)
{
  levelPenalty = 0;
  return;
}

int Character::getLevel(void) const
{
  int totalLevel = level - levelPenalty;
  return totalLevel;
}

// 6. Protected functions


// 7. Private functions

