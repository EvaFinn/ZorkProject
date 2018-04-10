#ifndef AXE_H
#define AXE_H

#include <string>
#include <iostream>
#include "item.h"
#include <QString>

using namespace std;

class Axe : public Item
{
private:
    string type;
    QString name;

public:
    Axe();
    ~Axe() {}
    string getType();
    QString getName();
};

#endif // AXE_H
