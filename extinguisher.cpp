#include "extinguisher.h"

Extinguisher::Extinguisher()
{
    this->type = "Extinguisher";
    this->name = "Extinguisher";
}

string Extinguisher::getType(){
    return this->type;
}

QString Extinguisher::getName(){
    return this->name;
}
