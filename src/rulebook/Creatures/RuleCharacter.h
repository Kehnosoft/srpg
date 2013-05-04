/*
 * Character.h
 *
 *  Created on: 13.3.2013
 *      Author: Juho L
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "RuleCreature.h"

enum character_profession
{
  battle_unit = 0
};

enum character_race
{
  eagle = 0
};

struct character_type
{
  character_profession profession;
  character_race race;
};

class Character : public Creature
{
  public:
    Character(const init_stats initStats, const character_type initType);
    ~Character(void);
    bool addExperience(int experienceIncrease);
    int getExperience(void) const;
    void applyLevelPenalty(int penalty);
    void removeLevelPenalty(void);
    int getLevel(void) const;
    // TODO: Leveling mechanics.

  private:
    int experience;
    int level;
    int levelPenalty;
    character_type type;
};

#endif /* CHARACTER_H_ */
