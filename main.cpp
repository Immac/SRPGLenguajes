#include "Elements/actionattack.h"
#include <iostream>
#include "Tests/catch.hpp"
#include "Tests/test.h"
#include "XML/loader.h"
#include "Console/consolehelper.h"
int main()
{
    string name;
    cout << "Nombre de la unidad: ";
    cin >> name;
    auto unit = Loader::loadUnit(name);
    auto unit2 = Loader::loadUnit(name);

    auto action = unit->mySkillSet.Actions.getAction("Attack");
    action->perform(unit,unit2);
    ConsoleHelper::unitPrint(unit2);
    return 0;
}
