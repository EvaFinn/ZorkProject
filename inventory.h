#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include <vector>


class Inventory //: QObject
{
//    Q_OBJECT

private:
    int numItems;
    int capacity;
//    Item **itemArr;
//    vector<Item> items;

public:
    Inventory();
    ~Inventory();
    void addItem(Item item);
    void removeItem(int index);
    void debugPrint();
    Item *items[2];
//    int getItems();

//signals:
//    void getInfo(QString itemType);

};

#endif // INVENTORY_H
