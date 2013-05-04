/*
 * Shield.cpp
 *
 *  Created on: Apr 3, 2013
 *      Author: juhol
 */

#include "../Errors.h"
#include "Shield.h"

Shield::Shield(item_data_struct& itemInfo, shield_data_struct& shieldInfo) :
Item(itemInfo),
shieldBonus(shieldInfo.shieldBonus),
resistanceTypes(shieldInfo.resistanceTypes),
chargeMax(shieldInfo.charge)
{
  shieldBonusMod = 0;
  resistanceTypeMods = 0;
  chargeLeft = 0;
  return;
}

Shield::~Shield(void)
{
  return;
}

void Shield::setShieldBonusMod(int modifier)
{
  shieldBonusMod = modifier;
  return;
}

int Shield::getShielBonus(void) const
{
  int totalMod = shieldBonus + shieldBonusMod;
  return totalMod;
}

void Shield::setDamageResistanceMod(bf types)
{
  resistanceTypeMods |= types;
  return;
}

bf Shield::getDamageResistance(void) const
{
  bf totalTypes = resistanceTypes | resistanceTypeMods;
  return totalTypes;
}

int Shield::getMaxCharge(void) const
{
  return chargeMax;
}

int Shield::getCharge(void) const
{
  return chargeLeft;
}

// Returns the amount of unabsorbed damage.
int Shield::decreaseCharge(int amount)
{
  if(amount > 0)
  {
    if(amount > chargeLeft)
    {
      amount -= chargeLeft;
      chargeLeft = 0;
    }
    else
    {
      chargeLeft -= amount;
      amount = 0;
    }
  }
  else
  {
    throw ErrorInvalidData();
  }
  return amount;
}
