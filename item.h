#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <QString>

class Item {

public:
    Item ();
    virtual ~Item() {}
    virtual QString getName() = 0;
};

#endif /*ITEM_H_*/
