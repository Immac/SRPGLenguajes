#include "Elements/actionattack.h"
#include <iostream>
#include "Tests/catch.hpp"
#include "Tests/test.h"
#include "XML/loader.h"
#include "Console/consolehelper.h"
int main()
{

    auto warrior = Loader::jobPtrFromFile("Warrior");
    auto assassin = Loader::jobPtrFromFile("Assassin");
    auto unit = Loader::unitFromFile("Immac");
    auto unit2 = Loader::unitFromFile("Alex");

    auto action = unit->mySkillSet.Actions.getAction("Attack");
    action->perform(unit,unit2);
    ConsoleHelper::unitPrint(*unit);
    return 0;
}
