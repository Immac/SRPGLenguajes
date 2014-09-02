#include "player.h"
Player::Player()
{
}

void Player::addUnit(Unit &unit)
{
    myUnits.insert(unit);
}

void Player::removeUnit(Unit &unit)
{
}
