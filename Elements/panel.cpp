#include "panel.h"



bool Panel::giveMyUnitTo(std::shared_ptr<Panel> newOwner)
{
    if(newOwner->recieveUnit(myUnit))
    {
        myUnit.reset();
        return true;
    }
    return false;
}

bool Panel::recieveUnit(std::shared_ptr<Unit> newUnit)
{
    if(myUnit)
        return false;
    myUnit = std::move(newUnit);
    return true;
}
