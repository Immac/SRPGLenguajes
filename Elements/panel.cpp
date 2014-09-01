#include "panel.h"



bool Panel::giveMyUnitTo(shared_ptr<Panel> newOwner)
{
    if(newOwner->recieveUnit(myUnit))
    {
        myUnit.reset();
        return true;
    }
    return false;
}

bool Panel::recieveUnit(shared_ptr<Unit> newUnit)
{
    if(myUnit)
        return false;
    myUnit = move(newUnit);
    return true;
}

Point Panel::getPointByOffset(Point offsetPoint)
{
    Point output= {myLocation.first + offsetPoint.first,
                        myLocation.second + offsetPoint.second};
    return output;
}

void Panel::fillAdjacentPanelByPosition(Point offsetPoint,
                                       shared_ptr<Panel> &output,
                                       vector<shared_ptr<Panel> > &input)
{
        auto iter = find_if(input.begin(),
                                 input.end(),
                                 IsPanelPosition(getPointByOffset(offsetPoint)) );
        if(iter != input.end())
            output = *iter;
}
void Panel::fillAdjacentPanels(vector<shared_ptr<Panel> > &mapPanels)
{
    fillAdjacentPanelByPosition(northOffset, northPanel ,mapPanels);
    fillAdjacentPanelByPosition(soutOffset, southPanel ,mapPanels);
    fillAdjacentPanelByPosition(eastOffset, eastPanel ,mapPanels);
    fillAdjacentPanelByPosition(westOffset, westPanel ,mapPanels);
}

