#include "Tests/test.h"
#include "Elements/actionattack.h"
#include <iostream>
int main()
{
    auto attackAction = ActionAttack();
    auto panel1 = Test::newPanel(0,0);
    auto panel2 = Test::newPanel(0,1);
    auto myUnit = Test::newUnitByJob();
    auto yourUnit = Test::newUnitByJob();
    attackAction.perform(myUnit,yourUnit,Test::statsInPlay());
    /*if(panel1->recieveUnit(std::move(myUnit)))
        std::cout << "Panel 1 recieved";
    if(panel1->giveMyUnitTo(panel2))
        std::cout << "Panel 2 recieved";
    if(panel2->giveMyUnitTo(panel1))
        std::cout << "Panel 1 recieved";*/
    attackAction.perform(myUnit,yourUnit,Test::statsInPlay());
    attackAction.perform(myUnit,yourUnit,Test::statsInPlay());
    attackAction.perform(yourUnit,myUnit,Test::statsInPlay());
    return 0;
}

