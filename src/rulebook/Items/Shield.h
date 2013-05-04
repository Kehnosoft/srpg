/*
 * Shield.h
 *
 *  Created on: Apr 3, 2013
 *      Author: juhol
 */

#ifndef SHIELD_H_
#define SHIELD_H_

#include "../TypeDefs.h"
#include "Item.h"
#include "../Creatures/Attack.h"

struct shield_data_struct
{
    int shieldBonus;
    bf resistanceTypes;
    int charge;
};

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
