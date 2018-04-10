#ifndef EXTINGUISHER_H
#define EXTINGUISHER_H

#include <string>
#include <QString>
#include "item.h"
using namespace std;

class Extinguisher : public Item
{
private:
    string type;
    QString name;

public:
    Extinguisher();
    ~Extinguisher() {}
    string getType();
    QString getName();
};

#endif // EXTINGUISHER_H
