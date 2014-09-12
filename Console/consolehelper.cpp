#include "consolehelper.h"

ConsoleHelper::ConsoleHelper()
{
}

string ConsoleHelper::unitPrint(Unit input)
{
    string output;
    string unitId = input.myId;
    output.append("Id: "+ unitId);
    auto name = input.getStat("Name");
    string unitName = name->getText();
    vector<StatDisplay> stats = getDisplaysFrom(input.myStatSystem.unitProperties);
    auto temp = getDisplaysFrom(input.myStatSystem.calculatedStats);
    stats.insert(stats.end(),temp.begin(),temp.end());
    temp = getDisplaysFrom(input.myStatSystem.jobStats());
    stats.insert(stats.end(),temp.begin(),temp.end());
    cout << "Unit Id: " << unitId << "\n";
    cout << "Name: " << unitName << "\n";
    cout << "Stats: \n";
    for(StatDisplay display:stats)
    {
        cout << "Name:\t\t" << display.id << "\n";
        cout << "Text:\t\t" << display.text << "\n";
        cout << "Current:\t " << to_string(display.currVal) << "\n";
        cout << "Normal\t\t: " << to_string(display.normVal) << "\n";
    }
    return output;
}

vector<StatDisplay> ConsoleHelper::getDisplaysFrom(set<ConsoleHelper::StatPtr> input)
{
    vector<StatDisplay> output;
    for(StatPtr stat: input)
    {
        StatDisplay temp;
        temp.id = stat->getId();
        temp.text = stat->getText();
        temp.currVal = stat->currentNumber;
        temp.normVal = stat->getDefaultNumber();
        output.push_back(temp);
    }
    return output;
}

