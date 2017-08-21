#ifndef PLAYER_H
#define PLAYER_H
#include "Elements/unit.h"

class Player
{
public:
    Player();
    void addUnit(shared_ptr<Unit> &unit);
    void removeUnit(shared_ptr<Unit> &unit);
    set<shared_ptr<Unit>> myUnits;
    int currency;
    //set<Currency> currency;
    //set<Items> myItems; //cosas
};

#endif // PLAYER_H
