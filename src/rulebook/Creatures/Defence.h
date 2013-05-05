//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-28
// Author:      Juho Lepisto
//
// Filename:    Defence.h
// Description: This is a defence class that calculates the different ACs and damage resistances
//              according to stats and equipment.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef DEFENCE_H_
#define DEFENCE_H_

// 1. External header files

#include "../../TypeDefs.h"
#include "Attack.h"
#include "Abilities.h"

// 2. Global enums, constants and macross

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

// 3. Global data structs


// 4. Class definition

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
