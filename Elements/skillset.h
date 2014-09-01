#ifndef SKILLSET_H
#define SKILLSET_H
#include "utilities.h"
#include "action.h"
class SkillSet
{
public:
    SkillSet(string name = string("Unnamed?")):name(name){}
    set<shared_ptr<Action>> Actions;
    set<shared_ptr<SkillSet>> SkillSubset;
    string getName() const;

private:
    string name;
};

#endif // SKILLSET_H
