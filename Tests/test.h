#ifndef TEST_H
#define TEST_H
#include "Elements/board.h"
#include "Elements/action.h"

class Test
{
public:
    Test() = default;
    static std::shared_ptr<Unit> newUnitByStats();
    static std::shared_ptr<Unit> newUnitByJob();
    static std::shared_ptr<Job> newJob();
    static std::shared_ptr<Stat> newStat(std::string name, std::string abbr, int defaultValue);
    static std::shared_ptr<Panel> newPanel(int x, int y)
    {
        return std::move(std::shared_ptr<Panel>(new Panel{x, y}));
    }
    static bool instantiationTest();
    static std::shared_ptr<Board> newBoard();
    static StatLists statsInPlay();


};

#endif // TEST_H
