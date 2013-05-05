//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-29
// Author:      Juho Lepisto
//
// Filename:    Weapon.h
// Description: This is a class for weapon type items.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef WEAPON_H_
#define WEAPON_H_

// 1. External header files

#include "../../TypeDefs.h"
#include "../Core/Dice.h"
#include "../Creatures/Attack.h"
#include "../Creatures/Defence.h"
#include "Item.h"

// 2. Global enums, constants and macross

enum weapon_type
{
  knife = 0
};

enum ammo_type
{
  none = 0,
  energy_cell
};

// 3. Global data structs

struct damage_dice_struct
{
    int dices;
    int diceValue;
    int criticalMultiplier;
};

struct ammo_struct
{
    ammo_type type;
    int ammoLeft;
    int capacity;
};

struct weapon_data_struct
{
    weapon_type type;
    damage_dice_struct damage_dice[max_attack_type_index];
    ammo_struct ammunition;
    int attackBonus[max_attack_type_index];
    int damageBonus[max_attack_type_index];
    bf damageTypes[max_attack_type_index];
    piercing_type piercing[max_attack_type_index][piercing_array_max];
    int ammoPerAttack[max_attack_type_index];
};

// 4. Class definition

class Weapon : public Item
{
  public:
    Weapon(item_data_struct& itemInfo, weapon_data_struct& weaponInfo);
    ~Weapon(void);

    void addDamageTypeMod(attack_type attack, bf types);
    void removeDamageTypeMod(attack_type attack, bf types);
    bf getDamageType(attack_type attack) const;

    void setAttackBonusMod(attack_type attack, int bonus);
    int getAttackBonus(attack_type attack) const;

    void setDamageBonusMod(attack_type attack, int bonus);
    int getDamageBonus(attack_type attack) const;

    void setPiercingMod(attack_type attack, defence_bonus_type type, piercing_type piercingLevel);
    piercing_type getPiercing(attack_type attack, defence_bonus_type type) const;

    void increaceAmmoCapacity(int increase);
    ammo_struct getAmmoInfo(void) const;

    bool reload(ammo_struct& ammo);
    bool emptyAmmo(ammo_struct& ammo);
    damage_struct rollDamage(attack_type attack) const;

  private:
    const Dice meleeDamageDice;
    const int meleeCritical;
    const Dice rangedDamageDice;
    const int rangedCritical;
    const weapon_type weapon;
    const int attackBonus[max_attack_type_index];
    const int damageBonus[max_attack_type_index];
    const bf damageTypes[max_attack_type_index];
    const ammo_type ammoType;
    const int ammoMax;
    const piercing_type piercing[max_attack_type_index][piercing_array_max];
    const int ammoPerAttack[max_attack_type_index];

    int attackBonusMod[max_attack_type_index];
    int damageBonusMod[max_attack_type_index];
    bf damageTypesMod[max_attack_type_index];
    piercing_type piercingMod[max_attack_type_index][piercing_array_max];
    int ammoLeft;
    int ammoMaxMod;
};

#endif /* WEAPON_H_ */
