#include "player.h"
Player::Player()
{
}

void Player::addUnit(shared_ptr<Unit> &unit)
{
    myUnits.insert(unit);
}

void Player::removeUnit(shared_ptr<Unit> &unit)
{
    auto hasSameName = [&](shared_ptr<Unit> unitPtr)
    {
        return unit->myId == unitPtr->myId;
    };
    auto unitItr = find_if(myUnits.begin(),myUnits.end(),hasSameName);
    myUnits.erase(unitItr);
}
