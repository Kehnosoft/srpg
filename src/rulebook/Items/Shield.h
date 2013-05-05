//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-04-03
// Author:      Juho Lepisto
//
// Filename:    Shield.h
// Description: This is a class for shield type items.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef SHIELD_H_
#define SHIELD_H_

// 1. External header files

#include "../../TypeDefs.h"
#include "Item.h"
#include "../Creatures/Attack.h"

// 2. Global enums, constants and macross


// 3. Global data structs

struct shield_data_struct
{
    int shieldBonus;
    bf resistanceTypes;
    int charge;
};

// 4. Class definition

class Shield : public Item
{
  public:
    Shield(item_data_struct& itemInfo, shield_data_struct& shieldInfo);
    ~Shield(void);

    void setShieldBonusMod(int modifier);
    int getShielBonus(void) const;

    void setDamageResistanceMod(bf types);
    bf getDamageResistance(void) const;

    int getMaxCharge(void) const;
    int getCharge(void) const;
    int decreaseCharge(int amount);

  private:
    const int shieldBonus;
    const bf resistanceTypes;
    const int chargeMax;

    int shieldBonusMod;
    bf resistanceTypeMods;
    int chargeLeft;
};

#endif /* SHIELD_H_ */
