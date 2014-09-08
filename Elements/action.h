#ifndef ACTION_H
#define ACTION_H
#include "utilities.h"
struct StatLists
{
    set<string> effectEnhancers;
    set<string> effectDetractors;
    set<string> affectedStats;
};
class Action
{
protected:
    typedef shared_ptr<Unit> UnitPtr ;
public:
    Action(string name,string formula = string("") ):
        actionName(name),
        actionFormula(formula)
        {}
    bool virtual perform(UnitPtr &subject ,
                         UnitPtr &object,
                         StatLists statsInPlay) = 0;
    string virtual getActionName() const;
private:
    string actionName;
    string actionFormula;
};

#endif // ACTION_H
