#include "board.h"
bool Board::addPanel(std::shared_ptr<Panel> panel)
{
    panels.push_back(panel);
    return true;
}

std::shared_ptr<Panel> Board::selectPanelOnCoordinate(Point point)
{
    panel = (*std::find_if(panels.begin(),panels.end(),IsPanelPosition(point) ) );
    return panel;
}

void Board::linkPanels()
{
    for(auto &singlePanel:panels)
    {
        singlePanel->fillAdjacentPanels(panels);
    }
}

