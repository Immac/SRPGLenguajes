#ifndef BOARD_H
#define BOARD_H
#include "panel.h"
class Board
{
public:
    Board(std::vector<std::shared_ptr<Panel>> input):panels(input){}
    bool addPanel(std::shared_ptr<Panel> panel);

private:
    std::vector<std::shared_ptr<Panel>> panels;
    /** Debug **/
    void fill();
};

#endif // BOARD_H
