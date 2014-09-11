#ifndef LOADER_H
#define LOADER_H
#include "tinyxml2.h"
#include "Elements/board.h"
#include <Elements/actionattack.h>
class Loader
{
private:
    typedef shared_ptr<Job> JobPtr;
    typedef shared_ptr<Stat> StatPtr;
    typedef shared_ptr<Unit> UnitPtr;
    typedef shared_ptr<ActionAttack> ActionPtr;
    typedef shared_ptr<SkillSet> SkillSetPtr;
public:
    Loader();
    static JobPtr jobPtrFromFile(string jobName);
    static JobPtr jobPtrFromNode(tinyxml2::XMLElement *root);
    static set<StatPtr> statSetFromNode(tinyxml2::XMLElement *root);
    static StatPtr statFromNode(tinyxml2::XMLElement *root);
    static set<string> participantStatsFromNode(tinyxml2::XMLElement *root);
    static UnitPtr unitFromFile(string unitId);
    static UnitPtr unitFromNode(tinyxml2::XMLElement *root);
    static map<JobPtr,int> levelUpsFromNode(tinyxml2::XMLElement *root);
    static string textFromNode(string nodeName, tinyxml2::XMLElement *root);
    static StatSystem statSystemFromNode(tinyxml2::XMLElement *root);
    static SkillSet skillSetPtrFromNode(tinyxml2::XMLElement *root);
    static ActionPtr actionFromNode(tinyxml2::XMLElement *root);

private:
    static bool isNotExpected(tinyxml2::XMLElement *element, string expected);
    static constexpr const char* kUnexpectedRoot = "Unexpected root";
    static constexpr const char* kNodeNotFound = "Node not found";
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
    static constexpr const char* kNodeStatSystem = "statsystem";
    static constexpr const char* kNodeAction = "action";
    static constexpr const char* kNodeSubjectStat = "subjectstat";
    static constexpr const char* kNodeObjectStat = "objectstat";
    static constexpr const char* kNodeAffectedStat = "affectedstat";
    static constexpr const char* kStat = "stat";
    static constexpr const char* kJob = "job";
    static constexpr const char* kUnit = "unit";
    static constexpr const char* kName = "name";
    static constexpr const char* kAttributeId = "id";
    static constexpr const char* kAttributeText = "text";
    static constexpr const char* kAttributeNormal = "normal";
    static constexpr const char* kAttributeCurrent = "current";
    static constexpr const char* kFormula = "formula";
    static constexpr const char* kLevels = "levels";

};

#endif // LOADER_H
