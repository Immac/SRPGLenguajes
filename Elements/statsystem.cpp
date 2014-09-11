#include "statsystem.h"

StatSystem::StatPtr StatSystem::getUnitProperty(string name)
{

    auto statItr = find_if(unitProperties.begin(),
                           unitProperties.end(),
                           IsStatNamed(name));
    if(statItr == unitProperties.end())
        return shared_ptr<Stat> (new Stat(statNotFound));

    shared_ptr<Stat> stat = (*statItr);
    return stat;
}

set<StatSystem::StatPtr> StatSystem::jobStats()
{
    return currentJob->getJobStats();
}

bool StatSystem::computeStats()
{
    calculatedStats.clear();
    for(StatPtr statItr : baseJob->getBaseStats())
        calculatedStats.insert(StatPtr(new Stat(*statItr)));
    for(pair<JobPtr,int> const &var:levelUps)
        growStats(var.first, var.second);
    return true;
}

bool StatSystem::growStats(JobPtr job, int multiplier)
{
    set<StatPtr> statSet = job->getGrowthStats();
    for(StatPtr stat:statSet)
    {
        auto isStatSame = [&] (StatPtr statPtr)
            {
                return *statPtr == *stat;
            };
        auto statItr = find_if(calculatedStats.begin(),
                               calculatedStats.end(),
                               isStatSame);
        if(statItr == calculatedStats.end())
        {
            auto statBase = job->getBaseStats();
            auto baseIter = statBase.find(stat);
            StatPtr foundBase = *baseIter;
            calculatedStats.insert(foundBase);
            statItr = calculatedStats.find(stat);//Review this> Unnecesary find?
        }
        StatPtr foundStat = *statItr;
        int growth = stat->getDefaultNumber();
        foundStat->grow(growth * multiplier);
    }
    return true;
}