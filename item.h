#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <QObject>

using namespace std;

class Item {

public:
    Item ();
    virtual ~Item() {}
    virtual string getType();

};

#endif /*ITEM_H_*/
