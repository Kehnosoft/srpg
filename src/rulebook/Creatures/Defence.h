/*
 * Defence.h
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#ifndef DEFENCE_H_
#define DEFENCE_H_

#include "Abilities.h"

enum bonus_type
{
  armor = 0,
  shield,
  attunement_protection,
  natural,
  deflection
};

enum AC_type
{
  normal = 0,
  touch,
  flatFooted
};

enum piercing_type
{
  no_piercing = 0,
  half_piercing,
  full_piercing
};

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
  electrical_damage
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

static const int damage_resistance_array_max = electrical_damage + 1;

class Defence
{
  public:
    Defence(const Abilities* abilityPointer);
    ~Defence(void);

    void addBonus(bonus_type type, int bonus);
    void decreaseBonus(bonus_type type, int bonus);
    int getAC(AC_type type, const piercing_type* piercing) const;

    int getDamageResistance(damage_type type) const;
    void addDamageResistance(damage_type type, int resistance);
    void decreaseDamageResistance(damage_type type, int resistance);

  private:
    static const int bonus_type_max = deflection + 1;
    static const int piercing_array_max = attunement_protection + 1;

    const Abilities* abilities;
    int armorBonuses[bonus_type_max];

    int damageResistance[damage_resistance_array_max];
};


#endif /* DEFENCE_H_ */
