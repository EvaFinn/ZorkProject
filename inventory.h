#ifndef INVENTORY_H
#define INVENTORY_H

#include "extinguisher.h"
#include "axe.h"

template<typename T>
class Inventory: public Extinguisher, public Axe
{
//    Q_OBJECT

private:
    int numItems;
    //int capacity;
      T *itemArr;
//    vector<Item> items;

public:
    Inventory();
    ~Inventory();
    void addItem(T item);
    //void removeItem(int index);
   // void debugPrint();
    //Item *items[2];
//    int getItems();

//signals:
//    void getInfo(QString itemType);

};

#endif // INVENTORY_H
