#include "test.h"
std::shared_ptr<Unit> Test::newUnit()
{
    const int level(10);
    const int unitId(1);
    const string skillSetName("MySkillSet");
    SkillSet skillSet(skillSetName);
    StatSystem statSystem(unitId);
    auto job = newJob();
    std::map<std::shared_ptr<Job>,int> jobList
    {
        {job,level}
    };
    statSystem.levelUps = jobList;
    statSystem.currentJob = job;
    statSystem.baseJob = job;
    string unitName = "Testo";
    std::shared_ptr<Unit> unit(new Unit(unitName,statSystem,skillSet));
    return unit;
}

std::shared_ptr<Job> Test::newJob()
{
    auto newBaseStats
    {
        std::shared_ptr<Stat>(std::move(new Stat(kHpName,kHpAbbr,100))),
        std::shared_ptr<Stat>(std::move(new Stat(kAtkName,kAtkAbbr,75))),
        std::shared_ptr<Stat>(std::move(new Stat(kDefName,kDefAbbr,70)))
    };
    auto newGrowthStats
    {
        std::shared_ptr<Stat>(std::move(new Stat(kHpName,kHpAbbr,8))),
        std::shared_ptr<Stat>(std::move(new Stat(kAtkName,kAtkAbbr,7))),
        std::shared_ptr<Stat>(std::move(new Stat(kDefName,kDefAbbr,6)))
    };
    auto newJobStats
    {
        std::shared_ptr<Stat>(std::move(new Stat(kMovName,kMovAbbr,4))),
        std::shared_ptr<Stat>(std::move(new Stat(kJmpName,kJmpAbbr,3))),
    };
    auto myJob = new Job(string("Tester"),newBaseStats,newGrowthStats,newJobStats);
    return std::move(std::shared_ptr<Job>(std::move(myJob)));
}

std::shared_ptr<Stat> Test::newStat(std::string name, std::string abbr, int defaultValue)
{
    return std::shared_ptr<Stat>(new Stat(name,abbr,defaultValue));
}

std::shared_ptr<Panel> Test::newPanel(int x, int y)
{
    return std::move(std::shared_ptr<Panel>(new Panel{x, y}));
}

bool Test::instantiationTest()
{
    /*auto panel = new Panel{0,0};
    auto newStats
    {
        std::shared_ptr<Stat>(std::move(new Stat(kHpName,kHpAbbr,100))),
        std::shared_ptr<Stat>(std::move(new Stat(kAtkName,kAtkAbbr,75))),
        std::shared_ptr<Stat>(std::move(new Stat(kDefName,kDefAbbr,70)))
    };
    auto localNewUnit = newUnitByStats();*/
    return true;
}

StatLists Test::AtkDefHpInPlay()
{
    StatLists output;
    output.effectEnhancers = {"Attack"};
    output.effectDetractors = {"Defense"};
    output.affectedStats = {"Health"};
    return output;
}

std::shared_ptr<Board> Test::newBoard()
{
    std::vector<std::shared_ptr<Panel>> panels;
    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
        {
            panels.push_back(newPanel(x,y));
        }
    }
    std::shared_ptr<Board> output {new Board(std::move(panels))};
    shared_ptr<Panel> localSelectPanelOnCoordinate = output->selectPanelOnCoordinate(Point(0,0));
    auto myUnit = Test::newUnit();
    localSelectPanelOnCoordinate->recieveUnit(std::move(myUnit));
    return output;
}
