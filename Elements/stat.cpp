#include "stat.h"

int Stat::getDefaultNumber() const
{
    return defaultNumber;
}
bool Stat::operator ==(const Stat &other) const
{
    return other.getId() == id;
}
string Stat::getText() const
{
    return text;
}
string Stat::getId() const
{
    return id;
}
