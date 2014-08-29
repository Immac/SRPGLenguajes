#ifndef JOB_H
#define JOB_H
#include "stat.h"

class Job
{
public:
    Job(std::set<std::shared_ptr<Stat>>baseStats,std::set<std::shared_ptr<Stat>>(growthStats)):
        baseStats(baseStats),growthStats(growthStats){}
    std::set<std::shared_ptr<Stat>> getBaseStats() const;
    std::set<std::shared_ptr<Stat>> getGrowthStats() const;

private:
    std::set<std::shared_ptr<Stat>> baseStats;
    std::set<std::shared_ptr<Stat>> growthStats;
    //TODO Skillset

};

#endif // JOB_H
