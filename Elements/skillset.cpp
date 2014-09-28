#include "skillset.h"

SkillSet::ActionPtr SkillSet::getAction(string actionName)
{
    return Actions.getAction(actionName);
}

SkillSet::SkillSetPtr SkillSet::getSubset(string subsetName)
{
    auto isNamed = [&](SkillSetPtr skillsetPtr)
    {
        return skillsetPtr->getName() == subsetName;
    };
    auto actionItr = find_if(SkillSubsets.begin(),
                             SkillSubsets.end(),
                             isNamed);
    if(actionItr != SkillSubsets.end())
        return (*actionItr);
    SkillSetPtr notFound(new SkillSet(subsetName + string("Not Found!")));
    return notFound;
}
