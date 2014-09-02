#include "job.h"

set<shared_ptr<Stat>> Job::getBaseStats() const
{
    return baseStats;
}
set<shared_ptr<Stat>> Job::getGrowthStats() const
{
    return growthStats;
}
set<shared_ptr<Stat> > Job::getJobStats() const
{
    return jobStats;
}
