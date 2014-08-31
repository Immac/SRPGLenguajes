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
    bool giveMyUnitTo(std::shared_ptr<Panel> newOwner);
    bool recieveUnit(std::shared_ptr<Unit> newUnit);
    void fillAdjacentPanels(std::vector<std::shared_ptr<Panel> > &mapPanels);

private:
    Point myLocation;
    std::shared_ptr<Unit> myUnit = nullptr;
    std::shared_ptr<Panel> northPanel;
    std::shared_ptr<Panel> southPanel;
    std::shared_ptr<Panel> eastPanel;
    std::shared_ptr<Panel> westPanel;
private:
    const Point northOffset = {0,1};
    const Point soutOffset = {0,-1};
    const Point eastOffset = {1,0};
    const Point westOffset = {-1,0};
private:
    Point getPointByOffset(Point offsetPoint);
    void fillAdjacentPanelByPosition(Point offsetPoint,
                                    std::shared_ptr<Panel> &output,
                                    std::vector<std::shared_ptr<Panel> > &input);
};

class IsPanelPosition
{
public:
    IsPanelPosition(Point inputPoint):
        inputPoint(inputPoint){}
    bool operator ()(std::shared_ptr<Panel> inputPanel)
    {
        return (inputPanel->myLocation.first == inputPoint.first) && (inputPanel->myLocation.second == inputPoint.second);
    }

private:
    Point inputPoint;
};


#endif // PANEL_H
