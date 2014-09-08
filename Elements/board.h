#ifndef BOARD_H
#define BOARD_H
#include "panel.h"
#include "unitset.h"
class Board
{
private:
    typedef shared_ptr<Panel> PanelPtr;
    typedef shared_ptr<Unit> UnitPtr;
public:
    Board(vector<PanelPtr> mapPanels):
        panels(mapPanels)
        {linkPanels();}
    bool addPanel(PanelPtr panel);
    bool giveUnitToPanel(UnitPtr &unit,PanelPtr &panel);
    PanelPtr selectPanelOnCoordinate(Point point);
    vector<PanelPtr> selectedPanelUnitMoveRange();
    PanelPtr const getSelectedPanel() { return selectedPanel; }
    UnitSet unitsInMap;

private:
    vector<PanelPtr> panels;
    PanelPtr selectedPanel;
    void linkPanels();
};


#endif // BOARD_H
