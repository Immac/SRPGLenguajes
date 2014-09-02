#include "board.h"
bool Board::addPanel(shared_ptr<Panel> panel)
{
    panels.push_back(panel);
    return true;
}

shared_ptr<Panel> Board::selectPanelOnCoordinate(Point point)
{
    selectedPanel = (*find_if(panels.begin(),panels.end(),IsPanelPosition(point) ) );
    return selectedPanel;
}

void Board::linkPanels()
{
    for(auto &singlePanel : panels)
        singlePanel->fillAdjacentPanels(panels);
}

