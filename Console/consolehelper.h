#ifndef CONSOLEHELPER_H
#define CONSOLEHELPER_H
#include "Elements/board.h"
#include <iostream>
struct StatDisplay
{
    string id;
    string text;
    int currVal;
    int normVal;
};

class ConsoleHelper
{
private:
    typedef shared_ptr<Unit> UnitPtr;
    typedef shared_ptr<Stat> StatPtr;
public:
    ConsoleHelper();
    static string unitPrint(Unit input);
    static vector<StatDisplay> getDisplaysFrom(set<StatPtr> input);
};

#endif // CONSOLEHELPER_H
