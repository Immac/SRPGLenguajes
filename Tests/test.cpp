#include "test.h"
shared_ptr<Unit> Test::newUnit()
{
    const int level(10);
    const int unitId(1);
    const string skillSetName("MySkillSet");
    SkillSet skillSet(skillSetName);
    StatSystem statSystem(unitId);
    auto job = newJob();
    map<shared_ptr<Job>,int> jobList
    {
        {job,level}
    };
    statSystem.levelUps = jobList;
    statSystem.currentJob = job;
    statSystem.baseJob = job;
    string unitName = "Testo";
    shared_ptr<Unit> unit(new Unit(unitName,statSystem,skillSet));
    return unit;
}

shared_ptr<Job> Test::newJob()
{
    auto newBaseStats
    {
        shared_ptr<Stat>(move(new Stat(kHpName,kHpAbbr,100))),
        shared_ptr<Stat>(move(new Stat(kAtkName,kAtkAbbr,75))),
        shared_ptr<Stat>(move(new Stat(kDefName,kDefAbbr,70)))
    };
    auto newGrowthStats
    {
        shared_ptr<Stat>(move(new Stat(kHpName,kHpAbbr,8))),
        shared_ptr<Stat>(move(new Stat(kAtkName,kAtkAbbr,7))),
        shared_ptr<Stat>(move(new Stat(kDefName,kDefAbbr,6)))
    };
    auto newJobStats
    {
        shared_ptr<Stat>(move(new Stat(kMovName,kMovAbbr,4))),
        shared_ptr<Stat>(move(new Stat(kJmpName,kJmpAbbr,3))),
    };
    auto myJob = new Job(string("Tester"),newBaseStats,newGrowthStats,newJobStats);
    return move(shared_ptr<Job>(move(myJob)));
}

shared_ptr<Stat> Test::newStat(string name, string abbr, int defaultValue)
{
    return shared_ptr<Stat>(new Stat(name,abbr,defaultValue));
}

shared_ptr<Panel> Test::newPanel(int x, int y)
{
    return move(shared_ptr<Panel>(new Panel{x, y}));
}

bool Test::instantiationTest()
{
    /*auto panel = new Panel{0,0};
    auto newStats
    {
        shared_ptr<Stat>(move(new Stat(kHpName,kHpAbbr,100))),
        shared_ptr<Stat>(move(new Stat(kAtkName,kAtkAbbr,75))),
        shared_ptr<Stat>(move(new Stat(kDefName,kDefAbbr,70)))
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

shared_ptr<Board> Test::newBoard()
{
    vector<shared_ptr<Panel>> panels;
    for (int x = 0; x < 10; ++x)
    {
        for (int y = 0; y < 10; ++y)
        {
            panels.push_back(newPanel(x,y));
        }
    }
    shared_ptr<Board> output {new Board(move(panels))};
    shared_ptr<Panel> localSelectPanelOnCoordinate = output->selectPanelOnCoordinate(Point(0,0));
    auto myUnit = Test::newUnit();
    localSelectPanelOnCoordinate->recieveUnit(move(myUnit));
    return output;
}
