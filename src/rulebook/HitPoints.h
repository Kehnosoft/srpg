/*
 * HitPoints.h
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#ifndef HITPOINTS_H_
#define HITPOINTS_H_

#include "Dice.h"

class HitPoints
{
  public:
    HitPoints(int value);
    ~HitPoints(void);

    void setMaxHitPoints(int hitPoints);
    int getMaxHitPoints(int hitPoints) const;
    int getHitPoints(void) const;

    int heal(int healPoints);
    int healAll(void);
    int takeDamage(int damagePoints);

    // TODO: Mahdollisuus rollata hipareita lis‰‰.

  private:
    const Dice hitDie;
    int max;
    int current;
};

#endif /* HITPOINTS_H_ */
