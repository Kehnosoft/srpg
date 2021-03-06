//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-23
// Author:      Juho Lepisto
//
// Filename:    Inventory.h
// Description: This is a class for creature inventory.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef INVENTORY_H_
#define INVENTORY_H_

// 1. External header files

#include "../Creatures/Abilities.h"
#include "Item.h"

// 2. Global enums, constants and macross


// 3. Global data structs


// 4. Class definition

class Inventory
{
  public:
    Inventory(const Abilities* abilityPointer);
    ~Inventory(void);

  private:
    const Abilities* abilities;
};


#endif /* INVENTORY_H_ */
