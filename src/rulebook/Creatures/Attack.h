//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-28
// Author:      Juho Lepisto
//
// Filename:    Attack.h
// Description: This is an attack class that generates hit and damage rolls according to the
//              creature's stats and equipment.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef ATTACK_H_
#define ATTACK_H_

// 1. External header files

#include "../../TypeDefs.h"
#include "Abilities.h"

// 2. Global enums, constants and macross

enum damage_type
{
  piercing_damage = 0,
  bludgeoning_damage,
  slashing_damage,
  laser_damage,
  plasma_damage,
  attunement_damage,
  explosive_damage,
  fire_damage,
  frost_damage,
  chemical_damage,
  radiation_damage,
  electrical_damage,
  nonlethal_damage
};

static const bf piercing_bit = 1UL << piercing_damage;
static const bf bludgeoning_bit = 1UL << bludgeoning_damage;
static const bf slashing_bit = 1UL << slashing_damage;
static const bf laser_bit = 1UL << laser_damage;
static const bf plasma_bit = 1UL << plasma_damage;
static const bf attunement_bit = 1UL << attunement_damage;
static const bf explosive_bit = 1UL << explosive_damage;
static const bf fire_bit = 1UL << fire_damage;
static const bf frost_bit = 1UL << frost_damage;
static const bf electrical_bit = 1UL << electrical_damage;
static const bf nonlethal_bit = 1UL << nonlethal_damage;

static const bf damage_type_max = nonlethal_bit;
static const int damage_resistance_array_max = electrical_damage + 1;

enum piercing_type
{
  no_piercing = 0,
  half_piercing,
  full_piercing
};

enum attack_type
{
  melee = 0,
  ranged
};

enum attack_bonus_type
{
  base_melee_attack_bonus = 0,
  base_ranged_attack_bonus,
  dual_main_hand_bonus,
  dual_off_hand_bonus
};

static const int max_attack_bonus_index = dual_off_hand_bonus + 1;
static const int max_attack_type_index = ranged + 1;

// 3. Global data structs

struct damage_struct
{
    int ammoLeft;
    bf type;
    int amount;
};

// 4. Class definition

class Attack
{
  public:
    Attack(const Abilities* abilityPointer);
    ~Attack(void);

  private:
    const Abilities* abilities;
    int attackBonus[max_attack_bonus_index];
};


#endif /* ATTACK_H_ */
