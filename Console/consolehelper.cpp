#include "consolehelper.h"

ConsoleHelper::ConsoleHelper()
{
}

string ConsoleHelper::unitPrint(shared_ptr<Unit> input)
{
    string output;
    string unitId = input->myId;
    output.append("Id: "+ unitId);
    auto name = input->getStat("Name");
    string unitName = name->getText();
    string jobName = input->myStatSystem.baseJob->getName();
    vector<StatDisplay> stats = getDisplaysFrom(input->myStatSystem.unitProperties);
    auto temp = getDisplaysFrom(input->myStatSystem.calculatedStats);
    stats.insert(stats.end(),temp.begin(),temp.end());
    temp = getDisplaysFrom(input->myStatSystem.jobStats());
    stats.insert(stats.end(),temp.begin(),temp.end());
    cout << "Unit Id: " << unitId << "\n";
    cout << "Name: " << unitName << "\n";
    cout << "Job: " << jobName << "\n";
    cout << "Stats: \n";
    for(StatDisplay display:stats)
    {
        cout << display.id << ": " << display.text << "\n";
        cout << to_string(display.currVal) << "/" << to_string(display.normVal) << "\n";
    }
    return output;
}

vector<StatDisplay> ConsoleHelper::getDisplaysFrom(vector<ConsoleHelper::StatPtr> input)
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

