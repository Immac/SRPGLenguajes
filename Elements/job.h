#ifndef JOB_H
#define JOB_H
#include "skillset.h"
#include "stat.h"


class Job
{
public:
    Job(string name = "Unspecified Error"):myName(name){}
    Job(string name,
        vector<shared_ptr<Stat>>baseStats,
        vector<shared_ptr<Stat>>growthStats,
        vector<shared_ptr<Stat>>jobStats
        ):
        myName(name),
        baseStats(baseStats),
        growthStats(growthStats),
        jobStats(jobStats){}
    string const getName() {return myName;}
    vector<shared_ptr<Stat> > getBaseStats() const;
    vector<shared_ptr<Stat> > getGrowthStats() const;
    vector<shared_ptr<Stat> > getJobStats() const;
private:
    string myName;
    vector<shared_ptr<Stat>> baseStats;
    vector<shared_ptr<Stat>> growthStats;
    vector<shared_ptr<Stat>> jobStats;
    shared_ptr<SkillSet> learnableSkills;
};

#endif // JOB_H
