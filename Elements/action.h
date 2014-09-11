#ifndef ACTION_H
#define ACTION_H
#include "utilities.h"
struct ParticipantStats
{
    set<string> Subject;
    set<string> Object;
    set<string> Affected;
};

class Action
{
protected:
    typedef shared_ptr<Unit> UnitPtr ;
    typedef shared_ptr<Action> ActionPtr;
public:
    Action(string name):actionName(name){}
    Action(string name,
           ParticipantStats participantStats,
           string formula = string("")):
        participantStats(participantStats),
        actionName(name),
        actionFormula(formula)
        {}
    bool virtual perform(UnitPtr subject ,
                         UnitPtr object) = 0;
    string virtual getActionName() const;
    string virtual getActionFormula() const;
protected:
    ParticipantStats participantStats;
    string actionName;
    string actionFormula;
};

#endif // ACTION_H
