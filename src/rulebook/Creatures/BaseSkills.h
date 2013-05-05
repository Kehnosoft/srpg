//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-29
// Author:      Juho Lepisto
//
// Filename:    BaseSkills.h
// Description: This is a base skills class that is common to all creatures, players and
//              enemies alike.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef BASESKILLS_H_
#define BASESKILLS_H_

// 1. External header files

#include "../../TypeDefs.h"
#include "Abilities.h"

// 2. Global enums, constants and macross

enum skill_type
{
  climbing = 0,
  perception,
  stealth,
  meditation
};

static const bf climbing_bit = 1UL << climbing;
static const bf perception_bit = 1UL << perception;
static const bf stealth_bit = 1UL << stealth;
static const bf meditation_bit = 1UL << meditation;

static const int skill_array_size = meditation + 1;
static const bf max_skill_bit = meditation_bit;

static const ability_type skillAbilityMods[skill_array_size] = {
  strength,   // climbing
  attunement, // perception
  dexterity,  // stealth
  attunement  // meditation
};

// 3. Global data structs

struct skill_struct
{
  int points;
  int bonus;
  int tempMod;
};

// 4. Class definition

class BaseSkills
{
  public:
    BaseSkills(const Abilities* abilityPointer);
    ~BaseSkills(void);

    void increaseSkill(skill_type type, int value);
    void setSkillPoints(skill_type type, int value);
    int getSkillPoints(skill_type type) const;

    void increaseSkillBonus(skill_type type, int value);
    void decreaseSkillBonus(skill_type type, int value);
    void increaseSkillTempMod(skill_type type, int value);
    void decreaseSkillTempMod(skill_type type, int value);

    void setTrainedSkill(bf skills);
    void removeTrainedSkill(bf skills);

  private:
    const Abilities* abilities;
    skill_struct skills[skill_array_size];
    bf trainedSkills;
};

#endif /* BASESKILLS_H_ */
