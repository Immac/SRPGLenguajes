#ifndef UNITSET_H
#define UNITSET_H
#include "unit.h"
class UnitSet
{
private:
    typedef shared_ptr<Unit> UnitPtr;
public:
    UnitSet();
    UnitPtr getUnit(string name);
    set<UnitPtr> unitSet;
};

#endif // UNITSET_H
