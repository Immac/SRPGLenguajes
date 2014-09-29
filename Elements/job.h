#ifndef JOB_H
#define JOB_H
#include "skillset.h"
#include "stat.h"


class Job
{
private:
    typedef  shared_ptr<Stat> StatPtr;
public:
    Job(string name = "Unspecified Error");
    Job(string name,
        vector<shared_ptr<Stat>>baseStats,
        vector<shared_ptr<Stat>>growthStats,
        vector<shared_ptr<Stat>>jobStats
        );
    string getName() {return myName;} const
    vector<StatPtr> getBaseStats() const;
    vector<StatPtr> getGrowthStats() const;
    vector<StatPtr > getJobStats() const;
private:
    string myName;
    vector<shared_ptr<Stat>> baseStats;
    vector<shared_ptr<Stat>> growthStats;
    vector<shared_ptr<Stat>> jobStats;
    shared_ptr<SkillSet> learnableSkills;
};

#endif // JOB_H
