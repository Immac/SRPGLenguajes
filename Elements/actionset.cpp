#include "actionset.h"

ActionSet::ActionSet()
{
}

ActionSet::ActionPtr ActionSet::getAction(string actionName)
{
    auto hasName = [&](ActionPtr actionPtr)
    {
        return actionPtr->getActionName() == actionName;
    };
    auto actionItr = find_if(actions.begin(),actions.end(),hasName);
    if(actionItr != actions.end())
        return (*actionItr);
    ActionPtr notFound(new ActionError(kNotFound));
    return notFound;
}
