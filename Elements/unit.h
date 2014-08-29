#ifndef UNIT_H
#define UNIT_H
#include "stat.h"
#include "job.h"
class Unit
{
public:
    Unit(std::set<std::shared_ptr<Stat>> stats):
        stats(stats){}
    Unit(std::map<std::shared_ptr<Job>,int> lvlUps,std::shared_ptr<Job> baseJob,std::shared_ptr<Job> currentJob):
        lvlUps(lvlUps),baseJob(baseJob),currentJob(currentJob)
        { recalculateStats(); }

    std::shared_ptr<Job> getCurrentJob() const
        { return currentJob; }
    void setCurrentJob(const std::shared_ptr<Job> &value)
        { currentJob = value; }

    std::set<std::shared_ptr<Stat>>     stats;
private:
    bool recalculateStats();

    std::map<std::shared_ptr<Job>,int>  lvlUps;
    std::shared_ptr<Job>                baseJob;
    std::shared_ptr<Job>                currentJob;

    bool growStats(std::shared_ptr<Job> job, int multiplier);
};

#endif // UNIT_H
