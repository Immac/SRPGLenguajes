#include "actionattack.h"
bool ActionAttack::perform(shared_ptr<Unit> &subject, shared_ptr<Unit> &object, StatLists statsInPlay)
{
    int enhanceValue = 0;
    int detractValue = 0;
    for(auto statName: statsInPlay.effectEnhancers)
    {
        auto enhancerItr = find_if(subject->myStatSystem.calculatedStats.begin(),
                                   subject->myStatSystem.calculatedStats.end(),
                                   IsStatNamed(statName));
        if(enhancerItr == subject->myStatSystem.calculatedStats.end())
            continue;
        enhanceValue += (*enhancerItr)->currentNumber;
        (*enhancerItr)->currentNumber;
    }
    for(auto statName: statsInPlay.effectDetractors)
    {
        auto detractor = (*find_if(object->myStatSystem.calculatedStats.begin(),
                                   subject->myStatSystem.calculatedStats.end(),
                                   IsStatNamed(statName)));
        detractValue += detractor->currentNumber;
    }
    for(auto statName: statsInPlay.affectedStats)
    {
        auto affected = (*find_if(object->myStatSystem.calculatedStats.begin(),
                                  subject->myStatSystem.calculatedStats.end(),
                                  IsStatNamed(statName)));
        affected->currentNumber -= max(enhanceValue-detractValue,1);
    }
    //TODO: Clean this
    return true;
}
