#ifndef ACTIONERROR_H
#define ACTIONERROR_H
#include "action.h"
class ActionError :public Action
{
public:
    ActionError(string name):Action(name){}
public:
    bool perform(UnitPtr &subject,
                 UnitPtr &object,
                 ParticipantStats participantStats) override;
};

#endif // ACTIONERROR_H
