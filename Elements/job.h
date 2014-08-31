#ifndef JOB_H
#define JOB_H
#include "stat.h"

class Job
{
public:
    Job(std::set<std::shared_ptr<Stat>>baseStats,
        std::set<std::shared_ptr<Stat>>growthStats,
        std::set<std::shared_ptr<Stat>>jobStats
        ):
        baseStats(baseStats),
        growthStats(growthStats),
        jobStats(jobStats){}

    std::set<std::shared_ptr<Stat>> getBaseStats() const;
    std::set<std::shared_ptr<Stat>> getGrowthStats() const;
    std::set<std::shared_ptr<Stat> > getJobStats() const;

private:
    std::set<std::shared_ptr<Stat>> baseStats;
    std::set<std::shared_ptr<Stat>> growthStats;
    std::set<std::shared_ptr<Stat>> jobStats;
    //TODO Skillset

};

#endif // JOB_H
