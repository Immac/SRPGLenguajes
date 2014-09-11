#ifndef ACTIONATTACK_H
#define ACTIONATTACK_H
#include "action.h"
#include "unit.h"
#include "Expression/expreval.h"

class ActionAttack: public Action
{
private:
    typedef vector<pair<string,int>> VariableList;
public:
    ActionAttack(string name,string formula = ""):
        Action(name,formula){}
    bool perform(UnitPtr &subject, UnitPtr &object, ParticipantStats participantStats) override;
    VariableList getVariables(set<string> input, UnitPtr &actor, string suffix);
    int computeVariables(VariableList variableList);
};

#endif // ACTIONATTACK_H
