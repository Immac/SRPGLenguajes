#ifndef ACTIONSET_H
#define ACTIONSET_H
#include "action.h"
#include "actionerror.h"
class ActionSet
{
private:
    const string kNotFound = "Not Found";
    typedef shared_ptr<Action> ActionPtr;
public:
    ActionSet();
    set<ActionPtr> actions;
    ActionPtr getAction(string actionName);
};

#endif // ACTIONSET_H
