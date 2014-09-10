#ifndef LOADER_H
#define LOADER_H
#include "tinyxml2.h"
#include "Elements/board.h"

class Loader
{
private:
    typedef shared_ptr<Job> JobPtr;
    typedef shared_ptr<Stat> StatPtr;
    typedef shared_ptr<Unit> UnitPtr;
public:
    Loader();
    static JobPtr jobPtrFromFile(string jobName);
    static JobPtr jobPtrFromNode(tinyxml2::XMLElement *baseNode);
    static set<StatPtr> statSetFromNode(tinyxml2::XMLElement *baseNode);
    static StatPtr statFromNode(tinyxml2::XMLElement *baseNode);
    static UnitPtr unitFromFile(string unitId);
    static UnitPtr unitFromNode(tinyxml2::XMLElement *root);
    static map<JobPtr,int> levelUpsFromNode(tinyxml2::XMLElement *root);
private:
    static bool isNotExpected(tinyxml2::XMLElement *element, string expected);
    static constexpr const char* kUnexpectedRoot = "Unexpected root";
    static constexpr const char* kErrorAt= "ERROR at:" ;
private:
    static constexpr const char* kNodeName = "name";
    static constexpr const char* kNodeId = "id";
    static constexpr const char* kNodeBaseStats = "basestats";
    static constexpr const char* kNodeGrowthStats = "growthstats";
    static constexpr const char* kNodeJobStats = "jobstats";
    static constexpr const char* kNodeBaseJob = "basejob";
    static constexpr const char* kNodeCurrentJob = "currentjob";
    static constexpr const char* kNodeUnitStats = "unitstats";
    static constexpr const char* kNodeLevels = "levels";
    static constexpr const char* kNodeSkillSet = "skillset";
    static constexpr const char* kStat = "stat";
    static constexpr const char* kJob = "job";
    static constexpr const char* kUnit = "unit";
    static constexpr const char* kAttributeId = "id";
    static constexpr const char* kAttributeText = "text";
    static constexpr const char* kAttributeNormal = "normal";
    static constexpr const char* kAttributeCurrent = "current";
    static constexpr const char* kLevels = "levels";

};

#endif // LOADER_H
