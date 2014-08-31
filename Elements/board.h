#ifndef BOARD_H
#define BOARD_H
#include "panel.h"
class Board
{
public:
    Board(std::vector<std::shared_ptr<Panel>> mapPanels):
        panels(mapPanels)
        {linkPanels();}
    bool addPanel(std::shared_ptr<Panel> panel);
    std::shared_ptr<Panel> selectPanelOnCoordinate(Point point);
    std::vector<std::shared_ptr<Panel>> selectedPanelUnitMoveRange();

private:
    std::vector<std::shared_ptr<Panel>> panels;
    std::shared_ptr<Panel> panel;
    /** Debug **/
    void linkPanels();
};


#endif // BOARD_H
