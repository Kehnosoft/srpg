/*
 * Attack.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#include "../Errors.h"
#include "../TypeDefs.h"
#include "../Core/Dice.h"
#include "Abilities.h"
#include "Attack.h"

Attack::Attack(const Abilities* abilityPointer) : abilities(abilityPointer)
{
  return;
}

Attack::~Attack(void)
{
  return;
}
