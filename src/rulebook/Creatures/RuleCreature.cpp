//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-28
// Author:      Juho Lepisto
//
// Filename:    RuleCreature.cpp
// Description: This is a base class for non-playable creatures.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "RuleCreature.h"

// 2. Local enums, constants and macross


// 3. Local global data structs and variables


// 4. Constructor and destructor

Creature::Creature(const init_stats initStats) :
abilities(initStats.abilityScores),
attack(&abilities),
defence(&abilities),
saves(&abilities),
inventory(&abilities),
health(initStats.hitPoints, &defence),
skills(&abilities)
{
  experienceReward = 0;
  return;
}

Creature::~Creature(void)
{
  return;
}

// 5. Public functions

void Creature::setExperienceReward(int reward)
{
  if(reward > 0)
  {
    experienceReward = reward;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

int Creature::getExperienceReward(void) const
{
  return experienceReward;
}

// 6. Protected functions


// 7. Private functions

