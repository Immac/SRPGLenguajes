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
    static JobPtr loadJob(string jobName);
    static JobPtr makeJob(tinyxml2::XMLElement *root);
    static vector<StatPtr> makeStatSet(tinyxml2::XMLElement *root);
    static StatPtr makeStat(tinyxml2::XMLElement *root);
    static set<string> makeParticipantStat(tinyxml2::XMLElement *root);
    static UnitPtr loadUnit(string unitId);
    static UnitPtr makeUnit(tinyxml2::XMLElement *root);
    static map<JobPtr,int> makeLevelUps(tinyxml2::XMLElement *root);
    static string getText(string nodeName, tinyxml2::XMLElement *root);
    static StatSystem makeStatSystem(tinyxml2::XMLElement *root);
    static SkillSet makeSkillSet(tinyxml2::XMLElement *root);
    static ActionPtr makeAction(tinyxml2::XMLElement *root);
    static ActionPtr loadAction(string name);

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
    static constexpr const char* kFileAction = "action_file";
    static constexpr const char* kNodeSubjectStat = "subject_stat";
    static constexpr const char* kNodeObjectStat = "object_stat";
    static constexpr const char* kNodeAffectedStat = "affected_stat";
    static constexpr const char* kNodeAction = "actions";
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
