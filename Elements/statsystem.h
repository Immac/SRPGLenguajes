#ifndef LEVELUPS_H
#define LEVELUPS_H
#include "utilities.h"
#include "job.h"
class StatSystem
{
private:
    typedef shared_ptr<Job> JobPtr;
    typedef shared_ptr<Stat> StatPtr;
public:
    StatSystem() = default;
    StatSystem(map<JobPtr,int> levelUps,JobPtr baseJob,
               JobPtr currentJob,vector<StatPtr> unitStats):
        levelUps(levelUps),
        baseJob(baseJob),
        currentJob(currentJob),
        unitProperties(unitStats)
        {computeStats();}
    StatSystem(const StatSystem &other):
        levelUps(other.levelUps),
        baseJob(other.baseJob),
        currentJob(other.currentJob),
        calculatedStats(other.calculatedStats),
        unitProperties(other.unitProperties)
        {computeStats();}
    StatSystem( StatSystem &&other):
        levelUps(move(other.levelUps)),
        baseJob(move(other.baseJob)),
        currentJob(move(other.currentJob)),
        calculatedStats(move(other.calculatedStats)),
        unitProperties(move(other.unitProperties))
        {computeStats();}
    StatPtr getUnitProperty(string name);
    StatPtr getStat(string name);
    map<JobPtr,int> levelUps;
    JobPtr baseJob;
    JobPtr currentJob;
    vector<StatPtr> jobStats();
    vector<StatPtr> calculatedStats;
    vector<StatPtr> unitProperties;
    bool computeStats();
public:
    static constexpr const char * statNotFound = "Not Found";
private:
    bool growStats(JobPtr job, int multiplier);
    StatPtr getStatFrom(string name, vector<StatPtr> from);
};

#endif // LEVELUPS_H
