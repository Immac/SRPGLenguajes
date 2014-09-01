#ifndef ACTIONATTACK_H
#define ACTIONATTACK_H
#include "action.h"
#include "unit.h"


class ActionAttack: public Action
{
public:
    ActionAttack(string name,string formula = ""):
        Action(name,formula){}
    bool perform(shared_ptr<Unit> &subject, shared_ptr<Unit> &object, StatLists statsInPlay) override;
};

#endif // ACTIONATTACK_H
