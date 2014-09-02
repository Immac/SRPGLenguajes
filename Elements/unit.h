#ifndef UNIT_H
#define UNIT_H
#include "levelups.h"
#include "skillset.h"

class Unit
{
public:
    Unit(string unitName,StatSystem statSystem,SkillSet skillSet):
        myName(unitName),
        mySkillSet(skillSet),
        myStatSystem(statSystem)
        {}
    Unit(const Unit &other) noexcept :
        myName(other.myName),
        mySkillSet(other.mySkillSet),
        myStatSystem(other.myStatSystem)
        {}
    Unit(Unit &&other) noexcept :
        myName(move(other.myName)),
        mySkillSet(move(other.mySkillSet)),
        myStatSystem(move(other.myStatSystem))
        {}
    string myName;
    SkillSet mySkillSet;
    StatSystem myStatSystem;
};

#endif // UNIT_H
