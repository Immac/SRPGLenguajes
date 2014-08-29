#ifndef PANEL_H
#define PANEL_H
#include "unit.h"

class Panel
{
public:
    Panel(int x,int y):myLocation({x,y}){}
    Panel(Point location):myLocation(location){}
    bool giveMyUnitTo(std::shared_ptr<Panel> newOwner);
    bool recieveUnit(std::shared_ptr<Unit> newUnit);
private:
    Point myLocation;
    std::shared_ptr<Unit> myUnit = nullptr;
};

#endif // PANEL_H
