#ifndef UNIT_H
#define UNIT_H
#include "skillset.h"
#include "statsystem.h"


class Unit
{
private:
    const string errorHandleName = "Error";
public:
    Unit():myId(errorHandleName){}
    Unit(string unitId,StatSystem statSystem,SkillSet skillSet):
        myId(unitId),
        mySkillSet(skillSet),
        myStatSystem(statSystem)
        {}
    Unit(const Unit &other) noexcept :
        myId(other.myId),
        mySkillSet(other.mySkillSet),
        myStatSystem(other.myStatSystem)
        {}
    Unit(Unit &&other) noexcept :
        myId(move(other.myId)),
        mySkillSet(move(other.mySkillSet)),
        myStatSystem(move(other.myStatSystem))
        {}
    string myId;
    SkillSet mySkillSet;
    StatSystem myStatSystem;
    bool operator ==(const Unit &other) const;
};

#endif // UNIT_H
