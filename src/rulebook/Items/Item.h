/*
 * Item.h
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <string>

enum item_type
{
  junk_item = 0,
  weapon_item,
  armor_item
};

static const unsigned int max_item_name = 20;
static const unsigned int max_item_description = 100;

struct item_data_struct
{
    int itemWeight;
    const std::string* itemName;
    const std::string* itemDescription;
};

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
