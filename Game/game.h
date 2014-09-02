#ifndef GAME_H
#define GAME_H
#include "Elements/board.h"
#include "allegiance.h"
class Game: public Allegiance
{
public:
    Game();
    void init();
};

#endif // GAME_H
