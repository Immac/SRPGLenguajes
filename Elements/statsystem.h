#ifndef LEVELUPS_H
#define LEVELUPS_H
#include "utilities.h"
#include "job.h"
class StatSystem
{
public:
    StatSystem(int id):myId(id){}
    StatSystem(const StatSystem &other):
        name(other.name),
        levelUps(other.levelUps),
        baseJob(other.baseJob),
        currentJob(other.currentJob),
        calculatedStats(other.calculatedStats),
        otherStats(other.otherStats),
        myId(other.myId)
        {recalculateStats();}
    StatSystem( StatSystem &&other):
        name(move(other.name)),
        levelUps(move(other.levelUps)),
        baseJob(move(other.baseJob)),
        currentJob(move(other.currentJob)),
        calculatedStats(move(other.calculatedStats)),
        otherStats(move(other.otherStats)),
        myId(move(other.myId))
        {recalculateStats();}
    string name;
    map<shared_ptr<Job>,int> levelUps;
    shared_ptr<Job> baseJob;
    shared_ptr<Job> currentJob;
    set<shared_ptr<Stat>> calculatedStats;
    set<shared_ptr<Stat>> otherStats;
    bool recalculateStats();
private:
    int myId;
    bool growStats(shared_ptr<Job> job, int multiplier);
};

#endif // LEVELUPS_H
