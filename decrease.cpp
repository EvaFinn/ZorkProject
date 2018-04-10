#include "decrease.h"

Decrease::Decrease()
{   }

Decrease::Decrease(int v)
{
   val = v;
}

Decrease Decrease::operator--(int)
{
    Decrease d(*this);
    val = val - 10;
    return d;
}
