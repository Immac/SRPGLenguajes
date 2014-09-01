#ifndef PANEL_H
#define PANEL_H
#include "unit.h"
class IsPanelPosition;


class Panel
{
public:
    Panel(int x,int y):myLocation({x,y}){}
    Panel(Point location):myLocation(location){}
    friend class IsPanelPosition;
    bool giveMyUnitTo(shared_ptr<Panel> newOwner);
    bool recieveUnit(shared_ptr<Unit> newUnit);
    void fillAdjacentPanels(vector<shared_ptr<Panel> > &mapPanels);

private:
    Point myLocation;
    shared_ptr<Unit> myUnit = nullptr;
    shared_ptr<Panel> northPanel;
    shared_ptr<Panel> southPanel;
    shared_ptr<Panel> eastPanel;
    shared_ptr<Panel> westPanel;
private:
    const Point northOffset = {0,1};
    const Point soutOffset = {0,-1};
    const Point eastOffset = {1,0};
    const Point westOffset = {-1,0};
private:
    Point getPointByOffset(Point offsetPoint);
    void fillAdjacentPanelByPosition(Point offsetPoint,
                                    shared_ptr<Panel> &output,
                                    vector<shared_ptr<Panel> > &input);
};

class IsPanelPosition
{
public:
    IsPanelPosition(Point inputPoint):
        inputPoint(inputPoint){}
    bool operator ()(shared_ptr<Panel> inputPanel)
    {
        return (inputPanel->myLocation.first == inputPoint.first) && (inputPanel->myLocation.second == inputPoint.second);
    }

private:
    Point inputPoint;
};


#endif // PANEL_H
