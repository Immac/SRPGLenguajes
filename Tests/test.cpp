#include "test.h"
int Test::randomInt(int minLevel, int maxLevel)
{
    typedef chrono::high_resolution_clock myClock;
    auto beginning = myClock::now();
    auto duration = myClock::now() - beginning;
    unsigned seed = duration.count();
    mt19937 random (seed);
    uniform_int_distribution<int> distribution(minLevel,maxLevel);

    const int level(distribution(random));

    return level;
}

shared_ptr<Unit> Test::newUnit()
{
    int minLevel = 9;
    int maxLevel = 12;

    const int level = randomInt( minLevel,maxLevel);
    const string skillSetName("MySkillSet");

    SkillSet skillSet(skillSetName);
    StatSystem statSystem;
    auto job = newJob();

    map<shared_ptr<Job>,int> jobList
    {
        {job,level}
    };
    auto newBaseStats
    {
        shared_ptr<Stat>(move(new Stat(kHpName,kHpAbbr,100))),
        shared_ptr<Stat>(move(new Stat(kAtkName,kAtkAbbr,75))),
        shared_ptr<Stat>(move(new Stat(kDefName,kDefAbbr,70)))
    };
    statSystem.levelUps = jobList;
    statSystem.currentJob = job;
    statSystem.baseJob = job;
    string unitId = "TestoId";
    shared_ptr<Unit> unit(new Unit(unitId,statSystem,skillSet));

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
    auto newJob = new Job(string("Tester"),newBaseStats,newGrowthStats,newJobStats);
    return move(shared_ptr<Job>(move(newJob)));
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
