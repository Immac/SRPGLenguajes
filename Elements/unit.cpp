#include "unit.h"


Unit::Unit(string unitId, StatSystem statSystem, SkillSet skillSet):
    myId(unitId),
    mySkillSet(skillSet),
    myStatSystem(statSystem)
{}

Unit::Unit(const Unit &other) :
    myId(other.myId),
    mySkillSet(other.mySkillSet),
    myStatSystem(other.myStatSystem)
{}

Unit::Unit(Unit &&other) :
    myId(move(other.myId)),
    mySkillSet(move(other.mySkillSet)),
    myStatSystem(move(other.myStatSystem))
{}

Unit::StatPtr Unit::getStat(string name)
{
    return myStatSystem.getStat(name);
}

bool Unit::operator ==(const Unit &other) const
{
    return myId == other.myId;
}
