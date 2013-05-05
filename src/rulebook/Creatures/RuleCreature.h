//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-28
// Author:      Juho Lepisto
//
// Filename:    RuleCreature.h
// Description: This is a base class for non-playable creatures.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef CREATURE_H_
#define CREATURE_H_

// 1. External header files

#include "../../TypeDefs.h"
#include "Abilities.h"
#include "Attack.h"
#include "Defence.h"
#include "SaveThrows.h"
#include "HitPoints.h"
#include "BaseSkills.h"
#include "../Items/Inventory.h"

// 2. Global enums, constants and macross

enum creature_type
{
  bandit = 0
};

// 3. Global data structs

struct init_stats
{
    int hitPoints;
    int abilityScores[ability_array_size];
};

// 4. Class definition

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
