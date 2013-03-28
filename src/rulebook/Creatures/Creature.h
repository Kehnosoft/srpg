/*
 * Creature.h
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#ifndef CREATURE_H_
#define CREATURE_H_

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

    Abilities abilities;
    Attack attack;
    Defence defence;
    SaveThrows saves;
    Inventory inventory;
    HitPoints health;

  private:
    //NA
};


#endif /* CREATURE_H_ */
