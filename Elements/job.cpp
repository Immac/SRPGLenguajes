#include "job.h"

Job::Job(string name):myName(name){}

Job::Job(string name, vector<StatPtr > baseStats, vector<StatPtr> growthStats, vector<StatPtr> jobStats):
    myName(name),
    baseStats(baseStats),
    growthStats(growthStats),
    jobStats(jobStats){}

vector<shared_ptr<Stat>> Job::getBaseStats() const
{
    return baseStats;
}
vector<shared_ptr<Stat>> Job::getGrowthStats() const
{
    return growthStats;
}
vector<Job::StatPtr> Job::getJobStats() const
{
    return jobStats;
}
