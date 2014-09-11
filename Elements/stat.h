#ifndef STAT_H
#define STAT_H
#include "utilities.h"

class Stat
{
private:
public:
    Stat(string id):
        id(id)
        {}
    Stat(string id,string defaultText,int defaultNumber):
        Stat(id,defaultText,defaultNumber,defaultNumber)
        {}
    Stat(string id,string defaultText,int defaultNumber,int currentNumber):
        currentNumber(currentNumber),
        id(id),text(defaultText),
        defaultNumber(defaultNumber)
        {}
    void grow(int growthNumber)
        {currentNumber = defaultNumber += growthNumber;}
    int getDefaultNumber() const;
    string getId() const;
    string getText() const;
    bool operator ==(const Stat &other) const;

public:
    int currentNumber;
private:
    string id;
    string text;
    int defaultNumber;
};

class IsStatNamed
{
public:
    IsStatNamed(string id = ""):
        id(id){}
    bool operator ()(shared_ptr<Stat> stat)
    {
        return stat->getId() == id;
    }
private:
    string id;
};

#endif // STAT_H
