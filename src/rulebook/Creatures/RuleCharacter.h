//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-13
// Author:      Juho Lepisto
//
// Filename:    RuleCharacter.h
// Description: This is a base class for player characters.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef CHARACTER_H_
#define CHARACTER_H_

// 1. External header files

#include "RuleCreature.h"

// 2. Global enums, constants and macross

enum character_profession
{
  battle_unit = 0
};

enum character_race
{
  eagle = 0
};

// 3. Global data structs

struct character_type
{
  character_profession profession;
  character_race race;
};

// 4. Class definition

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
