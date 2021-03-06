#include "statsystem.h"

StatSystem::StatPtr StatSystem::getUnitProperty(string name)
{
    return getStatFrom(name,unitProperties);
}

StatSystem::StatPtr StatSystem::getStat(string name)
{
    string notfound(statNotFound);
    auto output = getUnitProperty(name);
    if (output->getId() != notfound)
        return output;
    output = getStatFrom(name,calculatedStats);
    if (output->getId() != notfound)
        return output;
    output = getStatFrom(name,jobStats());
    return output;
}
StatSystem::StatPtr StatSystem::getStatFrom(string name, vector<StatSystem::StatPtr> from)
{
    auto statItr = find_if(from.begin(),
                           from.end(),
                           IsStatNamed(name));
    if(statItr == from.end())
    {
        string notfound(statNotFound);
        return shared_ptr<Stat> (new Stat(notfound));
    }


    shared_ptr<Stat> stat = (*statItr);
    return stat;
}
vector<StatSystem::StatPtr> StatSystem::jobStats()
{
    return currentJob->getJobStats();
}

bool StatSystem::computeStats()
{
    calculatedStats.clear();
    for(StatPtr statItr : baseJob->getBaseStats())
        calculatedStats.push_back(StatPtr(new Stat(*statItr)));
    for(pair<JobPtr,int> const &var:levelUps)
        growStats(var.first, var.second);
    return true;
}

bool StatSystem::growStats(JobPtr job, int multiplier)
{
    vector<StatPtr> statSet = job->getGrowthStats();
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
            auto baseIter = find(statBase.begin(),statBase.end(),stat);
            StatPtr foundBase = *baseIter;
            calculatedStats.push_back(foundBase);
            statItr = find(calculatedStats.begin(),calculatedStats.end(),stat);//Review this> Unnecesary find?
        }
        StatPtr foundStat = *statItr;
        int growth = stat->getDefaultNumber();
        foundStat->grow(growth * multiplier);
    }
    return true;
}


