#ifndef STAT_H
#define STAT_H
#include "utilities.h"

class Stat
{
public:
    Stat(std::string name,std::string abbr,int defaultValue):
        name(name),shortName(abbr),defaultValue(defaultValue),currentValue(defaultValue){}
    void grow(int growthValue) {currentValue = defaultValue += growthValue;}
    int getDefaultValue() const;
    std::string getName() const;
    bool operator ==(const Stat &other) const;
    std::string getShortName() const;

private:
    std::string name;
    std::string shortName;
    int defaultValue;

public:
    int currentValue;

};

class IsStatNamed
{
public:
    IsStatNamed(std::string name = ""):
        name(name){}
    bool operator ()(std::shared_ptr<Stat> atkStat)
    {
        return atkStat->getName() == name;
    }
private:
    std::string name;
};

#endif // STAT_H
