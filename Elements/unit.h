#ifndef UNIT_H
#define UNIT_H
#include "skillset.h"
#include "statsystem.h"


class Unit
{
private:
    typedef shared_ptr<Stat> StatPtr;
    static constexpr const char* errorHandleName = "Undefined Error";
public:
    Unit(string id = errorHandleName):myId(id){}
    Unit(string unitId,StatSystem statSystem,SkillSet skillSet);
    Unit(const Unit &other) noexcept;
    Unit(Unit &&other) noexcept;
    string myId;
    SkillSet mySkillSet;
    StatSystem myStatSystem;
    StatPtr getStat(string name);
    bool operator ==(const Unit &other) const;
};

#endif // UNIT_H
