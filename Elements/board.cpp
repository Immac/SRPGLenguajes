#include "board.h"
bool Board::addPanel(shared_ptr<Panel> panel)
{
    panels.push_back(panel);
    return true;
}

shared_ptr<Panel> Board::selectPanelOnCoordinate(Point point)
{
    panel = (*find_if(panels.begin(),panels.end(),IsPanelPosition(point) ) );
    return panel;
}
shared_ptr<Panel> Board::getPanel() const
{
    return panel;
}






void Board::linkPanels()
{
    for(auto &singlePanel:panels)
    {
        singlePanel->fillAdjacentPanels(panels);
    }
}

