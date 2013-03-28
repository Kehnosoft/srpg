/*
 * Inventory.cpp
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#include "../Errors.h"
#include "../Creatures/Abilities.h"
#include "Inventory.h"

Inventory::Inventory(const Abilities* abilityPointer) : abilities(abilityPointer)
{
  return;
}

Inventory::~Inventory(void)
{
  return;
}
