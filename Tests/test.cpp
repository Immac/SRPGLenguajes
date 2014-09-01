#include "test.h"




std::shared_ptr<Unit> Test::newUnitByJob()
{
    SkillSet skillSet(string("MySkillSet"));
    StatSystem statSystem;
    auto job = newJob();
    std::map<std::shared_ptr<Job>,int> jobList{{job,1}};
    statSystem.levelUps = jobList;
    statSystem.currentJob = job;
    statSystem.baseJob = job;
    std::shared_ptr<Unit> unit(new Unit(statSystem,skillSet));
    return std::move(unit);
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
        std::shared_ptr<Stat>(std::move(new Stat(kJmpName,kJmpAbbr,2))),
    };
    auto myJob = new Job(newBaseStats,newGrowthStats,newJobStats);
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


    return output;
}
