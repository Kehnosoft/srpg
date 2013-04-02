/*
 * HitPoints.h
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#ifndef HITPOINTS_H_
#define HITPOINTS_H_

#include "../Core/Dice.h"
#include "Defence.h"
#include "Attack.h"

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

    // TODO: Option to roll HPs.

  private:
    const Dice hitDie;
    int max;
    int current;
    const Defence* defence;
};

#endif /* HITPOINTS_H_ */
