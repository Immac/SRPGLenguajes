#ifndef STAT_H
#define STAT_H
#include "utilities.h"

class Stat
{
public:
    typedef shared_ptr<Stat> StatPtr;
    Stat(string name,string abbr,int defaultValue):
        name(name),shortName(abbr),
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
    string name;
    string shortName;
    int defaultValue;

public:
    int currentValue;

};

class IsStatNamed
{
public:
    IsStatNamed(string name = ""):
        name(name){}
    bool operator ()(shared_ptr<Stat> atkStat)
    {
        return atkStat->getName() == name;
    }
private:
    string name;
};

#endif // STAT_H
