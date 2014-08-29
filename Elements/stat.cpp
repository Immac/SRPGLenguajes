#include "stat.h"

int Stat::getDefaultValue() const
{
    return defaultValue;
}
bool Stat::operator ==(const Stat &other) const
{
    return other.getName() == name;
}
std::string Stat::getShortName() const
{
    return shortName;
}
std::string Stat::getName() const
{
    return name;
}
