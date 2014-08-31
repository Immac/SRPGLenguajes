#ifndef ACTIONATTACK_H
#define ACTIONATTACK_H
#include "action.h"
#include "unit.h"


class ActionAttack: public Action
{
public:
    ActionAttack(std::string name,std::string formula = ""):
        Action(name,formula){}
    bool perform(std::shared_ptr<Unit> &subject, std::shared_ptr<Unit> &object, StatLists statsInPlay) override;
};

#endif // ACTIONATTACK_H
