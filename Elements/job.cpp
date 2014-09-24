#include "job.h"

vector<shared_ptr<Stat>> Job::getBaseStats() const
{
    return baseStats;
}
vector<shared_ptr<Stat>> Job::getGrowthStats() const
{
    return growthStats;
}
vector<shared_ptr<Stat> > Job::getJobStats() const
{
    return jobStats;
}
