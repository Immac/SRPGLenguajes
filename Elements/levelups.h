#ifndef LEVELUPS_H
#define LEVELUPS_H
#include "utilities.h"
#include "job.h"
class StatSystem
{
public:
    StatSystem() = default;
    StatSystem(const StatSystem &other):
        levelUps(other.levelUps),
        baseJob(other.baseJob),
        currentJob(other.currentJob),
        myStats(other.myStats)
        {recalculateStats();}
    StatSystem( StatSystem &&other):
        levelUps(move(other.levelUps)),
        baseJob(move(other.baseJob)),
        currentJob(move(other.currentJob)),
        myStats(move(other.myStats))
        {recalculateStats();}
    map<shared_ptr<Job>,int> levelUps;
    shared_ptr<Job> baseJob;
    shared_ptr<Job> currentJob;
    set<shared_ptr<Stat>> myStats;
    bool recalculateStats();
    bool growStats(shared_ptr<Job> job, int multiplier);
};

#endif // LEVELUPS_H
