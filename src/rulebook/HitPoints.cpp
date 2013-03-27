/*
 * HitPoints.cpp
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#include "Errors.h"
#include "Dice.h"
#include "HitPoints.h"

HitPoints::HitPoints(int value) : hitDie(1, value)
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
  return;
}

HitPoints::~HitPoints(void)
{
  return;
}

void HitPoints::setMaxHitPoints(int hitPoints)
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

int HitPoints::getMaxHitPoints(int hitPoints) const
{
  return max;
}

int HitPoints::getHitPoints(void) const
{
  return current;
}

int HitPoints::heal(int healPoints)
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

int HitPoints::takeDamage(int damagePoints)
{
  if(damagePoints >= 0)
  {
    current -= damagePoints;
  }
  else
  {
    throw ErrorInvalidData();
  }
  return damagePoints;
}
