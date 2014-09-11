#include "actionattack.h"
bool ActionAttack::perform(UnitPtr &subject, UnitPtr &object)
{
    VariableList variables = getVariables(participantStats.Object,object,"O");
    auto tempVariable = getVariables(participantStats.Subject,subject,"S");
    variables.insert(variables.end(),tempVariable.begin(),tempVariable.end());
    auto value = computeVariables(variables);
    for(auto statName: participantStats.Affected)
    {
        auto affected = object->getStat(statName);
        affected->currentNumber -= value;
    }
    return true;
}

ActionAttack::VariableList ActionAttack::getVariables(set<string> input,UnitPtr &actor,string suffix)
{
    VariableList variables;
    for(auto statName: input)
    {
        pair<string,int> var;
        auto stat = actor->getStat(statName);
        string notFound = StatSystem::statNotFound;
        if(stat->getId() == notFound)
            continue;
        var.first = stat->getText() + suffix;
        var.second = stat->currentNumber;
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
