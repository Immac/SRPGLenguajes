#ifndef JOB_H
#define JOB_H
#include "skillset.h"
#include "stat.h"


class Job
{
public:
    Job():myName("ERROR"){}
    Job(string name,
        set<shared_ptr<Stat>>baseStats,
        set<shared_ptr<Stat>>growthStats,
        set<shared_ptr<Stat>>jobStats
        ):
        myName(name),
        baseStats(baseStats),
        growthStats(growthStats),
        jobStats(jobStats){}
    string const getName() {return myName;}
    set<shared_ptr<Stat>> getBaseStats() const;
    set<shared_ptr<Stat>> getGrowthStats() const;
    set<shared_ptr<Stat> > getJobStats() const;
private:
    string myName;
    set<shared_ptr<Stat>> baseStats;
    set<shared_ptr<Stat>> growthStats;
    set<shared_ptr<Stat>> jobStats;
    shared_ptr<SkillSet> learnableSkills;
};

#endif // JOB_H
