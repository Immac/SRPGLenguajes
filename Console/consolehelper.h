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
    static string unitPrint(shared_ptr<Unit> input);
    static vector<StatDisplay> getDisplaysFrom(vector<StatPtr> input);
};

#endif // CONSOLEHELPER_H
