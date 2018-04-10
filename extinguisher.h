#ifndef EXTINGUISHER_H
#define EXTINGUISHER_H

#include <string>
#include <iostream>
#include "item.h"
using namespace std;

class Extinguisher : public Item
{
private:
    string type;

public:
    Extinguisher();
    ~Extinguisher() {}
    string getType();
};

#endif // EXTINGUISHER_H
