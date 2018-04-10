#include "decrease.h"

Decrease::Decrease(int v)
{
   val = v;
}

Decrease::operator--(int)
{
    Decrease d;
    d.val = d.val - 10;
    return d;
}

/*Decrease::getValue()
{
   return val;
}*/
