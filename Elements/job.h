#ifndef JOB_H
#define JOB_H
#include "stat.h"

class Job
{
public:
    Job(string name,
        set<shared_ptr<Stat>>baseStats,
        set<shared_ptr<Stat>>growthStats,
        set<shared_ptr<Stat>>jobStats
        ):
        myName(name),
        baseStats(baseStats),
        growthStats(growthStats),
        jobStats(jobStats){}
    string myName;
    set<shared_ptr<Stat>> getBaseStats() const;
    set<shared_ptr<Stat>> getGrowthStats() const;
    set<shared_ptr<Stat> > getJobStats() const;
private:
    set<shared_ptr<Stat>> baseStats;
    set<shared_ptr<Stat>> growthStats;
    set<shared_ptr<Stat>> jobStats;
    //TODO Skillset
};

#endif // JOB_H
