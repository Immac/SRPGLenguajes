#include "board.h"



bool Board::addPanel(std::shared_ptr<Panel> panel)
{
    panels.push_back(panel);
    return true;
}

