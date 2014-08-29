#include "job.h"

std::set<std::shared_ptr<Stat>> Job::getBaseStats() const
{
    return baseStats;
}

std::set<std::shared_ptr<Stat>> Job::getGrowthStats() const
{
    return growthStats;
}


