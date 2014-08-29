#include "test.h"


std::shared_ptr<Unit> Test::newUnitByStats()
{
    auto newStats
    {
        newStat(kHpName,kHpAbbr,100),
        newStat(kAtkName,kAtkAbbr,75),
        newStat(kDefName,kDefAbbr,80),
        newStat(kMovName,kMovAbbr,4),
        newStat(kJmpName,kJmpAbbr,3),
    };
    return std::move(std::shared_ptr<Unit>(new Unit(std::move(newStats))));;
}



std::shared_ptr<Unit> Test::newUnitByJob()
{
    auto job = newJob();
    std::map<std::shared_ptr<Job>,int> jobList{{job,1}};
    std::shared_ptr<Unit> unit(new Unit(jobList,job,job));
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

    auto myJob = new Job(newBaseStats,newGrowthStats);
    return std::move(std::shared_ptr<Job>(std::move(myJob)));
}

std::shared_ptr<Stat> Test::newStat(std::string name, std::string abbr, int defaultValue)
{
    return std::shared_ptr<Stat>(new Stat(name,abbr,defaultValue));
}

bool Test::instantiationTest()
{
    auto panel = new Panel{0,0};
    auto newStats
    {
        std::shared_ptr<Stat>(std::move(new Stat(kHpName,kHpAbbr,100))),
        std::shared_ptr<Stat>(std::move(new Stat(kAtkName,kAtkAbbr,75))),
        std::shared_ptr<Stat>(std::move(new Stat(kDefName,kDefAbbr,70)))
    };
    auto localNewUnit = newUnitByStats();
    return true;
}

StatLists Test::statsInPlay()
{
    StatLists output;
    output.effectEnhancers = {"Attack"};
    output.effectDetractors = {"Defense"};
    output.affectedStats = {"Health"};
    return output;
}
