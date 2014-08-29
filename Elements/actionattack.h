#ifndef ACTIONATTACK_H
#define ACTIONATTACK_H
#include "action.h"
#include "unit.h"


class ActionAttack: public Action
{
public:
    ActionAttack():
    Action(std::string("Attack"),std::string("")){}
    bool perform(std::shared_ptr<Unit> &subject, std::shared_ptr<Unit> &object, StatLists statsInPlay) override;
};

#endif // ACTIONATTACK_H
