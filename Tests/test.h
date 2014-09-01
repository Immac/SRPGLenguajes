#ifndef TEST_H
#define TEST_H
#include "Elements/board.h"
#include "Elements/action.h"

class Test
{
public:
    Test() = default;
    static std::shared_ptr<Unit> newUnitByJob();
    static std::shared_ptr<Job> newJob();
    static std::shared_ptr<Stat> newStat(std::string name, std::string abbr, int defaultValue);
    static std::shared_ptr<Panel> newPanel(int x, int y);
    static std::shared_ptr<Board> newBoard();
    static bool instantiationTest();
    static StatLists AtkDefHpInPlay();


};

#endif // TEST_H
