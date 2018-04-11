#ifndef EXTINGUISHER_H
#define EXTINGUISHER_H

#include <string>
#include <QString>
#include "item.h"
using namespace std;

class Extinguisher : public Item
{
private:
    QString name;

public:
    Extinguisher();
    ~Extinguisher() {}
    QString getName();
};

#endif // EXTINGUISHER_H
