/*
 * Creature.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#include "../Errors.h"
#include "Creature.h"

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
