#ifndef STAT_H
#define STAT_H
#include "utilities.h"

class Stat
{
public:
    Stat(string statName,string abbr,int defaultValue):
        myName(statName),shortName(abbr),
        defaultValue(defaultValue),
        currentValue(defaultValue)
        {}
    void grow(int growthValue)
        {currentValue = defaultValue += growthValue;}
    int getDefaultValue() const;
    string getName() const;
    bool operator ==(const Stat &other) const;
    string getShortName() const;

private:
    string myName;
    string shortName;
    int defaultValue;

public:
    int currentValue;

};

class IsStatNamed
{
public:
    IsStatNamed(string name = ""):
        myName(name){}
    bool operator ()(shared_ptr<Stat> atkStat)
    {
        return atkStat->getName() == myName;
    }
private:
    string myName;
};

#endif // STAT_H
