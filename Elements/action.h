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
public:
    Action(string name,string formula = string("") ):
        actionName(name),actionFormula(formula){}
    bool virtual perform(shared_ptr<Unit> &subject , shared_ptr<Unit> &object, StatLists statsInPlay) = 0;
    bool learned;
private:
    string actionName;
    string actionFormula;
};

#endif // ACTION_H
