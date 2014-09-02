#ifndef BOARD_H
#define BOARD_H
#include "panel.h"
class Board
{
public:
    Board(vector<shared_ptr<Panel>> mapPanels):
        panels(mapPanels)
        {linkPanels();}
    bool addPanel(shared_ptr<Panel> panel);
    shared_ptr<Panel> selectPanelOnCoordinate(Point point);
    vector<shared_ptr<Panel>> selectedPanelUnitMoveRange();
    shared_ptr<Panel> const getSelectedPanel() { return selectedPanel; }

private:
    vector<shared_ptr<Panel>> panels;
    shared_ptr<Panel> selectedPanel;
    void linkPanels();
};


#endif // BOARD_H
