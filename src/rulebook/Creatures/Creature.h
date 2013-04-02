/*
 * Creature.h
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include "../TypeDefs.h"
#include "Abilities.h"
#include "Attack.h"
#include "Defence.h"
#include "SaveThrows.h"
#include "HitPoints.h"
#include "BaseSkills.h"
#include "../Items/Inventory.h"

enum creature_type
{
  bandit = 0
};

struct init_stats
{
    int hitPoints;
    int abilityScores[ability_array_size];
};

class Creature
{
  public:
    Creature(const init_stats initStats);
    ~Creature(void);

    void setExperienceReward(int reward);
    int getExperienceReward(void) const;

    Abilities abilities;
    Attack attack;
    Defence defence;
    SaveThrows saves;
    Inventory inventory;
    HitPoints health;
    BaseSkills skills;

  private:
    int experienceReward;
};


#endif /* CREATURE_H_ */
