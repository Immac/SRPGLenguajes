#ifndef PLAYER_H
#define PLAYER_H
#include "Elements/unit.h"

class Player
{
public:
    Player();
    void addUnit(Unit &unit);
    void removeUnit(Unit &unit);
    set<Unit> myUnits;
    int currency;
    //set<Currency> currency;
    //set<Items> myItems;
};

#endif // PLAYER_H
