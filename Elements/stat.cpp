#include "stat.h"

int Stat::getDefaultValue() const
{
    return defaultValue;
}
bool Stat::operator ==(const Stat &other) const
{
    return other.getName() == myName;
}
string Stat::getShortName() const
{
    return shortName;
}
string Stat::getName() const
{
    return myName;
}
