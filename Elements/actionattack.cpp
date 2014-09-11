#include "actionattack.h"
bool ActionAttack::perform(UnitPtr &subject, UnitPtr &object, ParticipantStats participantStats)
{
    VariableList variables = getVariables(participantStats.Object,object,"O");
    auto tempVariable = getVariables(participantStats.Subject,object,"S");
    variables.insert(variables.end(),tempVariable.begin(),tempVariable.end());
    auto value = computeVariables(variables);
    for(auto statName: participantStats.Affected)
    {
        auto affected = (*find_if(object->myStatSystem.calculatedStats.begin(),
                                  subject->myStatSystem.calculatedStats.end(),
                                  IsStatNamed(statName)));
        affected->currentNumber -= value;
    }
    //TODO: Clean this
    return true;
}

ActionAttack::VariableList ActionAttack::getVariables(set<string> input,UnitPtr &actor,string suffix)
{
    VariableList variables;
    for(auto statName: input)
    {
        pair<string,int> var;
        auto enhancerItr = find_if(actor->myStatSystem.calculatedStats.begin(),
                                   actor->myStatSystem.calculatedStats.end(),
                                   IsStatNamed(statName));
        if(enhancerItr == actor->myStatSystem.calculatedStats.end())
            continue;
        var.first = string((*enhancerItr)->getText()) + suffix;
        var.second = (*enhancerItr)->currentNumber;
        variables.push_back(var);
    }
    return variables;
}

int ActionAttack::computeVariables(VariableList variableList)
{
    using namespace ExprEval;
    ValueList value;
    FunctionList functionList;
    Expression expression;
    value.AddDefaultValues();
    functionList.AddDefaultFunctions();
    for(auto &pair:variableList)
        value.Add(pair.first,pair.second);
    expression.SetValueList(&value);
    expression.SetFunctionList(&functionList);
    auto formula = getActionFormula();
    expression.Parse(formula);
    auto result = expression.Evaluate();
    return result;
}
