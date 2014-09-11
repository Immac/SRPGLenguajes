#include "unit.h"


Unit::StatPtr Unit::getStat(string name)
{
    return myStatSystem.getStat(name);
}

bool Unit::operator ==(const Unit &other) const
{
    return myId == other.myId;
}
