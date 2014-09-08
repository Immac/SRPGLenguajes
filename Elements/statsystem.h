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
    StatSystem(const StatSystem &other):
        levelUps(other.levelUps),
        baseJob(other.baseJob),
        currentJob(other.currentJob),
        calculatedStats(other.calculatedStats),
        unitProperties(other.unitProperties)
        {recalculateStats();}
    StatSystem( StatSystem &&other):
        levelUps(move(other.levelUps)),
        baseJob(move(other.baseJob)),
        currentJob(move(other.currentJob)),
        calculatedStats(move(other.calculatedStats)),
        unitProperties(move(other.unitProperties))
        {recalculateStats();}
    StatPtr getUnitProperty(string name);
    map<JobPtr,int> levelUps;
    JobPtr baseJob;
    JobPtr currentJob;
    set<StatPtr> jobStats();
    set<StatPtr> calculatedStats;
    set<StatPtr> unitProperties;
    bool recalculateStats();
public:
    const string statNotFound = "Not Found";
private:
    bool growStats(JobPtr job, int multiplier);
};

#endif // LEVELUPS_H
