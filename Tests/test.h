#ifndef TEST_H
#define TEST_H
#include "Elements/board.h"
#include "Elements/action.h"
#include <random>
#include <chrono>
class Test
{
public:
    Test();
    static std::shared_ptr<Unit> newUnit();
    static std::shared_ptr<Job> newJob();
    static std::shared_ptr<Stat> newStat(std::string name, std::string abbr, int defaultValue);
    static std::shared_ptr<Panel> newPanel(int x, int y);
    static std::shared_ptr<Board> newBoard();
    static bool instantiationTest();
    static int randomInt(int minLevel, int maxLevel);
private:
};

#endif // TEST_H
