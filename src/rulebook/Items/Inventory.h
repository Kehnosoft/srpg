/*
 * Inventory.h
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

class Inventory
{
  public:
    Inventory(const Abilities* abilityPointer);
    ~Inventory(void);

  private:
    const Abilities* abilities;
};


#endif /* INVENTORY_H_ */
