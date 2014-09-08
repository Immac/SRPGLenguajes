#ifndef STAT_H
#define STAT_H
#include "utilities.h"

class Stat
{
private:
    const string defaultString = "N/A";
    const int nonSetValue = 0;
public:
    Stat(string id):Stat(id,defaultString,nonSetValue){}
    Stat(string id,string defaultText,int defaultNumber):
        currentNumber(defaultNumber),
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
