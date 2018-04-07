#ifndef AXE_H
#define AXE_H

#include <string>
#include <iostream>
#include "item.h"
using namespace std;

class Axe : public Item{
private:
    string type;

public:
    Axe();
    string getType();
};

#endif // AXE_H
