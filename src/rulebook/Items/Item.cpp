//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-23
// Author:      Juho Lepisto
//
// Filename:    Item.cpp
// Description: This is a base class for all items.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "Item.h"

// 2. Local enums, constants and macross


// 3. Local global data structs and variables


// 4. Constructor and destructor

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

// 5. Public functions

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

// 6. Protected functions


// 7. Private functions

