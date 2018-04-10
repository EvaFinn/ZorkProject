#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>


class Inventory{

private:
    int numItems;
    int capacity;
//    Item **itemArr;
//    vector<Item> items;

public:
    Inventory();
    ~Inventory();
    void addItem(Item item);
    Item *items[2];
//    int getItems();
};

#endif // INVENTORY_H
