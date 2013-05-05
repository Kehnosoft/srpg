//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-29
// Author:      Juho Lepisto
//
// Filename:    Weapon.cpp
// Description: This is a class for weapon type items.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "Weapon.h"

// 2. Local enums, constants and macross


// 3. Local global data structs and variables


// 4. Constructor and destructor

Weapon::Weapon(item_data_struct& itemInfo, weapon_data_struct& weaponInfo) :
Item(itemInfo),
meleeDamageDice(weaponInfo.damage_dice[melee].dices, weaponInfo.damage_dice[melee].diceValue),
meleeCritical(weaponInfo.damage_dice[melee].criticalMultiplier),
rangedDamageDice(weaponInfo.damage_dice[ranged].dices, weaponInfo.damage_dice[ranged].diceValue),
rangedCritical(weaponInfo.damage_dice[ranged].criticalMultiplier),
weapon(weaponInfo.type),
attackBonus{weaponInfo.attackBonus[melee], weaponInfo.attackBonus[ranged]},
damageBonus{weaponInfo.damageBonus[melee], weaponInfo.damageBonus[ranged]},
damageTypes{weaponInfo.damageTypes[melee], weaponInfo.damageTypes[ranged]},
ammoType(weaponInfo.ammunition.type),
ammoMax(weaponInfo.ammunition.capacity),
piercing{{weaponInfo.piercing[melee][armor], weaponInfo.piercing[melee][shield], weaponInfo.piercing[melee][attunement]},
         {weaponInfo.piercing[ranged][armor], weaponInfo.piercing[ranged][shield], weaponInfo.piercing[ranged][attunement]}},
ammoPerAttack{weaponInfo.ammoPerAttack[melee], weaponInfo.ammoPerAttack[ranged]}
{
  ammoLeft = 0;
  ammoMaxMod = 0;
  for(int i = 0; i < piercing_array_max; i++)
  {
    attackBonusMod[i] = 0;
    damageBonusMod[i] = 0;
    damageTypesMod[i] = 0;
  }
  Item::setType(weapon_item);
  return;
}

Weapon::~Weapon(void)
{
  return;
}

// 5. Public functions

void Weapon::addDamageTypeMod(attack_type attack, bf types)
{
  if(types <= damage_type_max)
  {
    damageTypesMod[attack] |= types;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

void Weapon::removeDamageTypeMod(attack_type attack, bf types)
{
  if(types <= damage_type_max)
  {
    damageTypesMod[attack] &= ~types;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

bf Weapon::getDamageType(attack_type attack) const
{
  bf totalTypes = damageTypes[attack] | damageTypesMod[attack];
  return totalTypes;
}

void Weapon::setAttackBonusMod(attack_type attack, int bonus)
{
  attackBonusMod[attack] = bonus;
  return;
}

int Weapon::getAttackBonus(attack_type attack) const
{
  int totalAttackBonus = attackBonus[attack] + attackBonusMod[attack];
  return totalAttackBonus;
}

void Weapon::setDamageBonusMod(attack_type attack, int bonus)
{
  damageBonusMod[attack] = bonus;
  return;
}

int Weapon::getDamageBonus(attack_type attack) const
{
  int totalDamageBonus = damageBonus[attack] + damageBonusMod[attack];
  return totalDamageBonus;
}

void Weapon::setPiercingMod(attack_type attack, defence_bonus_type type, piercing_type piercingLevel)
{
  if(type < piercing_array_max)
  {
    piercingMod[attack][type] = piercingLevel;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

piercing_type Weapon::getPiercing(attack_type attack, defence_bonus_type type) const
{
  piercing_type totalPiercing;
  if(piercing[attack][type] > piercingMod[attack][type])
  {
    totalPiercing = piercing[attack][type];
  }
  else
  {
    totalPiercing = piercingMod[attack][type];
  }
  return totalPiercing;
}

bool Weapon::reload(ammo_struct& clip)
{
  bool isReloadSuccess;
  if(clip.type == ammoType)
  {
    int space = (ammoMax + ammoMaxMod) - ammoLeft;
    if(space < clip.ammoLeft)
    {
      clip.ammoLeft -= space;
      ammoLeft += space;
    }
    else
    {
      ammoLeft += clip.ammoLeft;
      clip.ammoLeft = 0;
    }
    isReloadSuccess = true;
  }
  else
  {
    isReloadSuccess = false;
  }
  return isReloadSuccess;
}

bool Weapon::emptyAmmo(ammo_struct& clip)
{
  bool isEmptySuccess;
  if(clip.type == ammoType)
  {
    int space = clip.capacity - clip.ammoLeft;
    if(space < ammoLeft)
    {
      ammoLeft -= space;
      clip.ammoLeft += space;
    }
    else
    {
      clip.ammoLeft += ammoLeft;
      ammoLeft = 0;
    }
    isEmptySuccess = true;
  }
  else
  {
    isEmptySuccess = false;
  }
  return isEmptySuccess;
}

void Weapon::increaceAmmoCapacity(int increase)
{
  if(increase > 0)
  {
    ammoMaxMod += increase;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

ammo_struct Weapon::getAmmoInfo(void) const
{
  ammo_struct ammoInfo;
  ammoInfo.ammoLeft = ammoLeft;
  ammoInfo.capacity = ammoMax + ammoMaxMod;
  ammoInfo.type = ammoType;
  return ammoInfo;
}

damage_struct Weapon::rollDamage(attack_type attack) const
{
  damage_struct damage;

  switch(attack)
  {
    case melee:
      damage.type = damageTypes[melee];
      damage.amount = meleeDamageDice.roll() + damageBonus[melee];
      break;

    case ranged:
      damage.type = damageTypes[ranged];
      damage.amount = rangedDamageDice.roll() + damageBonus[ranged];
      break;

    default:
      throw ErrorUnexpectedValue();
      break;
  }

  return damage;
}

// 6. Protected functions


// 7. Private functions

