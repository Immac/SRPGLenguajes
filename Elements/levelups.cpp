#include "levelups.h"

bool StatSystem::recalculateStats()
{
    calculatedStats.clear();
    for(shared_ptr<Stat> statItr : baseJob->getBaseStats())
        calculatedStats.insert(shared_ptr<Stat>(new Stat(*statItr)));
    for(pair<shared_ptr<Job>,int> const &var:levelUps)
        growStats(var.first, var.second);
    return true;
}

bool StatSystem::growStats(shared_ptr<Job> job, int multiplier)
{
    set<shared_ptr<Stat> > statSet = job->getGrowthStats();
    for(shared_ptr<Stat> stat:statSet)
    {
        auto isStatSame = [&] (shared_ptr<Stat> statPtr) { return *statPtr == *stat; };
        auto statItr = find_if(calculatedStats.begin(),calculatedStats.end(),isStatSame);
        if(statItr == calculatedStats.end())
        {
            auto statBase = job->getBaseStats();
            auto baseIter = statBase.find(stat);
            shared_ptr<Stat> foundBase = *baseIter;
            calculatedStats.insert(foundBase);
            statItr = calculatedStats.find(stat);//Review this> Unnecesary find?
        }
        shared_ptr<Stat> foundStat = *statItr;
        int growth = stat->getDefaultValue();
        foundStat->grow(growth * multiplier);
    }
    return true;
}
