/*
 * Item.cpp
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#include "../Errors.h"
#include "Item.h"

Item::Item(item_data_struct& itemInfo)
{
  if(itemInfo.itemWeight < 1)
  {
    throw ErrorInvalidData();
  }
  if((itemInfo.itemName->size() > max_item_name) || (itemInfo.itemDescription->size() > max_item_description))
  {
    throw ErrorStringTooLong();
  }

  weight = itemInfo.itemWeight;
  name = *itemInfo.itemName;
  description = *itemInfo.itemDescription;
  type = junk_item;
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

item_type Item::getType(void)
{
  return type;
}

void Item::setType(item_type itemType)
{
  type = itemType;
  return;
}
