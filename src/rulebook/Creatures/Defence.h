/*
 * Defence.h
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#ifndef DEFENCE_H_
#define DEFENCE_H_

#include "../TypeDefs.h"
#include "Attack.h"
#include "Abilities.h"

enum defence_bonus_type
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

static const int piercing_array_max = attunement_protection + 1;
static const int bonus_type_max = deflection + 1;

class Defence
{
  public:
    Defence(const Abilities* abilityPointer);
    ~Defence(void);

    void addBonus(defence_bonus_type type, int bonus);
    void decreaseBonus(defence_bonus_type type, int bonus);
    int getAC(AC_type type, const piercing_type* piercing) const;

    int getDamageResistance(damage_type type) const;
    void addDamageResistance(damage_type type, int resistance);
    void decreaseDamageResistance(damage_type type, int resistance);

  private:
    const Abilities* abilities;
    int defenceBonuses[bonus_type_max];
    int damageResistances[damage_resistance_array_max];
};


#endif /* DEFENCE_H_ */
