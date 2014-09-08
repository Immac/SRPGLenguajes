#include "unit.h"


bool Unit::operator ==(const Unit &other) const
{
    return myId == other.myId;
}
