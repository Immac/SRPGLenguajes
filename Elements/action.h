#ifndef ACTION_H
#define ACTION_H
#include "utilities.h"
struct StatLists
{
    std::set<std::string> effectEnhancers;
    std::set<std::string> effectDetractors;
    std::set<std::string> affectedStats;
};
class Action
{
public:
    Action(std::string name,std::string formula = std::string("") ):
        actionName(name),actionFormula(formula){}
    bool virtual perform(std::shared_ptr<Unit> &subject , std::shared_ptr<Unit> &object, StatLists statsInPlay);
private:
    std::string actionName;
    std::string actionFormula;
};

#endif // ACTION_H
