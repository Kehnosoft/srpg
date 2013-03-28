/*
 * Item.cpp
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#include <string>
#include "../Errors.h"
#include "Item.h"

Item::Item(int itemWeight, std::string itemName)
{
  if(itemWeight < 1)
  {
    throw ErrorInvalidData();
  }
  if(itemName.size() > 20)
  {
    throw ErrorNameTooLong();
  }

  weight = itemWeight;
  name = itemName;
  type = junk;
  return;
}

Item::~Item(void)
{
  return;
}

int Item::getWeight(void)
{
  return weight;
}

item_t Item::getType(void)
{
  return type;
}

void Item::setType(item_t itemType)
{
  type = itemType;
  return;
}
