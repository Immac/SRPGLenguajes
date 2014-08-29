#include "unit.h"
bool Unit::recalculateStats()
{
    stats.clear();
    std::set<std::shared_ptr<Stat> > baseStats = baseJob->getBaseStats();
    for(std::shared_ptr<Stat> stat:baseStats)
        stats.insert( std::shared_ptr<Stat>(new Stat(*stat)) );
    for(std::pair<std::shared_ptr<Job>,int> const &var:lvlUps)
        growStats(var.first, var.second);
    return true;
}

bool Unit::growStats(std::shared_ptr<Job> job, int multiplier)
{
    std::set<std::shared_ptr<Stat> > statSet = job->getGrowthStats();
    for(std::shared_ptr<Stat> stat:statSet)
    {
        auto statComparer = [&] (std::shared_ptr<Stat> statPtr) { return *statPtr == *stat; };
        auto iter = std::find_if(stats.begin(),stats.end(),statComparer);
        if(iter == stats.end())
        {
            auto statBase = job->getBaseStats();
            auto baseIter = statBase.find(stat);
            std::shared_ptr<Stat> foundBase = *baseIter;
            stats.insert(foundBase);
            iter = stats.find(stat);
        }
        std::shared_ptr<Stat> foundStat = *iter;
        int growth = stat->getDefaultValue();
        foundStat->grow(growth * multiplier);
    }
    return true;
}
