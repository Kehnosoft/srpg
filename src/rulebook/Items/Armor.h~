/*
 * Armor.h
 *
 *  Created on: Mar 29, 2013
 *      Author: juhol
 */

#ifndef ARMOR_H_
#define ARMOR_H_

#include "Item.h"
#include "../Creatures/Defence.h"
#include "../Creatures/Character.h"

enum armor_type
{
  light = 0,
  medium,
  heavy
};

struct armor_data_struct
{
    armor_type type;
    int armorBonus;
    int damageResistances[damage_resistance_array_max];
    character_race raceType;
};

class Armor : public Item
{
  public:
    Armor(item_data_struct& itemInfo, armor_data_struct& armorInfo);
    ~Armor(void);

    void setArmorBonusMod(int modifier);
    int getArmorBonus(void) const;

    void setDamageResistanceMod(damage_type damageType, int modifier);
    int getDamageResistance(damage_type damageType) const;

    void setDeflectionBonus(int bonus);
    int getDeflectionBonus(void) const;

    void setArmorRaceType(character_race newRace);
    character_race getArmorRaceType(void) const;

  private:
    const armor_type type;
    const int armorBonus;
    const int damageResistances[damage_resistance_array_max];
    int armorBonusMod;
    int deflectionBonus;
    int damageResistanceMods[damage_resistance_array_max];
    character_race raceType;
};

#endif /* ARMOR_H_ */
