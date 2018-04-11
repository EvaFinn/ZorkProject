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
    QString name;

public:
    Axe();
    ~Axe() {}
    QString getName();
};

#endif // AXE_H
