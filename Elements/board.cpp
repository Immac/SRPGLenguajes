#include "board.h"
bool Board::addPanel(PanelPtr panel)
{
    panels.push_back(panel);
    linkPanels();
    return true;
}

bool Board::giveUnitToPanel(Board::UnitPtr &unit, Board::PanelPtr &panel)
{
    return panel->recieveUnit(unit);
}

Board::PanelPtr Board::selectPanelOnCoordinate(Point point)
{
    selectedPanel = (*find_if(panels.begin(),panels.end(),IsPanelPosition(point) ) );
    return selectedPanel;
}

vector<Board::PanelPtr> Board::selectedPanelUnitMoveRange()
{
    string moveStatName("Move");
    vector<PanelPtr> output;
    auto unitInPanel = selectedPanel->getMyUnit();
    if(unitInPanel == nullptr)
        return output;
    StattPtr stat = unitInPanel->myStatSystem.getUnitProperty(moveStatName);

}


void Board::linkPanels()
{
    for(auto &singlePanel : panels)
        singlePanel->fillAdjacentPanels(panels);
}

