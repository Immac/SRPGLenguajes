#ifndef SKILLSET_H
#define SKILLSET_H
#include "utilities.h"
#include "action.h"
class SkillSet
{
private:
    typedef shared_ptr<Action> ActionPtr;
    typedef shared_ptr<SkillSet> SkillSetPtr;
public:
    SkillSet(string skillSetName = string("Unnamed?")):
        myName(skillSetName)
        {}
    set<ActionPtr> Actions;
    set<SkillSetPtr> SkillSubset;
    string const getName() {return myName;}

private:
    string myName;
};

#endif // SKILLSET_H
