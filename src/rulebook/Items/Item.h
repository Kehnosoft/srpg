/*
 * Item.h
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#ifndef ITEM_H_
#define ITEM_H_

enum item_t
{
  junk = 0
};

class Item
{
  public:
    Item(int itemWeight, std::string itemName);
    ~Item(void);
    int getWeight(void);
    item_t getType(void);

  protected:
    void setType(item_t itemType);

  private:
    int weight;
    item_t type;
    std::string name;
    // TODO: Later add a description class that contains the item name and a short desccription.
};


#endif /* ITEM_H_ */
