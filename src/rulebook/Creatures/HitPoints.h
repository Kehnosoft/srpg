//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-20
// Author:      Juho Lepisto
//
// Filename:    HitPoints.h
// Description: This is a hit points class that keeps track on the hitpoints of the creature,
//              calculates healing/damage and rolls new hitpoints according to hit die and level.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef HITPOINTS_H_
#define HITPOINTS_H_

// 1. External header files

#include "../Core/Dice.h"
#include "Defence.h"
#include "Attack.h"

// 2. Global enums, constants and macross


// 3. Global data structs


// 4. Class definition

class HitPoints
{
  public:
    HitPoints(int value, const Defence* defencePointer);
    ~HitPoints(void);

    void setMaxHitPoints(const int hitPoints);
    int getMaxHitPoints(void) const;
    int getHitPoints(void) const;

    int heal(const int healPoints);
    int healAll(void);
    int takeDamage(const damage_struct& damage);

    void rollHitPoints(int dice);

  private:
    const Dice hitDie;
    int max;
    int current;
    const Defence* defence;
};

#endif /* HITPOINTS_H_ */
