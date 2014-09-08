#ifndef SKILLSET_H
#define SKILLSET_H
#include "actionset.h"
class SkillSet
{
private:
    typedef shared_ptr<Action> ActionPtr;
    typedef shared_ptr<SkillSet> SkillSetPtr;
public:
    SkillSet(string skillSetName = string("Unnamed?")):
        myName(skillSetName)
        {}
    ActionSet Actions;
    set<SkillSetPtr> SkillSubset;
    ActionPtr getAction(string actionName);
    string const getName() {return myName;}

private:
    string myName;
};

#endif // SKILLSET_H
