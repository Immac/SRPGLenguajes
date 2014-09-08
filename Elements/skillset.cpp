#include "skillset.h"

SkillSet::ActionPtr SkillSet::getAction(string actionName)
{
    return Actions.getAction(actionName);
}
