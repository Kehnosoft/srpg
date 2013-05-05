//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-23
// Author:      Juho Lepisto
//
// Filename:    Item.h
// Description: This is a base class for all items.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef ITEM_H_
#define ITEM_H_

// 1. External header files

#include <string>

// 2. Global enums, constants and macross

enum item_type
{
  junk_item = 0,
  weapon_item,
  armor_item
};

static const unsigned int max_item_name = 20;
static const unsigned int max_item_description = 100;

// 3. Global data structs

struct item_data_struct
{
    int itemWeight;
    const std::string* itemName;
    const std::string* itemDescription;
};

// 4. Class definition

class Item
{
  public:
    Item(item_data_struct& itemInfo);//int itemWeight, const std::string* itemName, const std::string* itemDescription);
    ~Item(void);
    int getWeight(void);
    item_type getType(void);

  protected:
    void setType(item_type itemType);

  private:
    int weight;
    item_type type;
    std::string name;
    std::string description;
};


#endif /* ITEM_H_ */
