#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <QString>

using namespace std;

class Item {

public:
    Item ();
    virtual ~Item() {}
    virtual QString getName();
};

#endif /*ITEM_H_*/
