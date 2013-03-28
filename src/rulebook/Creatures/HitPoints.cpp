/*
 * HitPoints.cpp
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#include "../Errors.h"
#include "../TypeDefs.h"
#include "../Core/Dice.h"
#include "Defence.h"
#include "Attack.h"
#include "HitPoints.h"

HitPoints::HitPoints(int value, const Defence* defencePointer) : hitDie(1, value), defence(defencePointer)
{
  if(value > 0)
  {
    max = value;
    current = value;
  }
  else
  {
    throw ErrorInvalidData();
  }
  if(defencePointer == 0)
  {
    throw ErrorNullPointer();
  }
  return;
}

HitPoints::~HitPoints(void)
{
  return;
}

void HitPoints::setMaxHitPoints(const int hitPoints)
{
  if(hitPoints > 0)
  {
    max = hitPoints;
    current = max;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

int HitPoints::getMaxHitPoints(void) const
{
  return max;
}

int HitPoints::getHitPoints(void) const
{
  return current;
}

int HitPoints::heal(const int healPoints)
{
  if(healPoints >= 0)
  {
    current += healPoints;
    if(current > max)
    {
      current = max;
    }
  }
  else
  {
    throw ErrorInvalidData();
  }
  return current;
}

int HitPoints::healAll(void)
{
  current = max;
  return current;
}

int HitPoints::takeDamage(const damage_struct& damage)
{
  int damageTaken;
  if(damage.amount >= 0)
  {
    damageTaken = damage.amount;

    bf currentType = 1;
    for(int i = piercing_damage; i < damage_resistance_array_max; i++)
    {
      if(damage.type & currentType)
      {
        int resist = defence->getDamageResistance(static_cast<damage_type>(i));
        if(resist)
        {
          damageTaken -= resist;
        }
      }
      currentType <<= 1;
    }

    if(damageTaken > 0)
    {
      current -= damageTaken;
    }
    else
    {
      damageTaken = 0;
    }
  }
  else
  {
    throw ErrorInvalidData();
  }
  return damageTaken;
}
