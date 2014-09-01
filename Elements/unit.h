#ifndef UNIT_H
#define UNIT_H
#include "levelups.h"
#include "skillset.h"

class Unit
{
public:
    Unit(StatSystem statSystem,SkillSet skillSet):
        mySkillSet(skillSet),
        myStatSystem(statSystem)
        {}
    Unit(const Unit &other):
        mySkillSet(other.mySkillSet),
        myStatSystem(other.myStatSystem)
        {}
    Unit(Unit &&other):
        mySkillSet(move(other.mySkillSet)),
        myStatSystem(move(other.myStatSystem))
        {}

    SkillSet mySkillSet;
    StatSystem myStatSystem;

};

#endif // UNIT_H
