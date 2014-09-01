#include "actionattack.h"
bool ActionAttack::perform(shared_ptr<Unit> &subject, shared_ptr<Unit> &object, StatLists statsInPlay)
{
    int enhanceValue = 0;
    int detractValue = 0;
    for(auto statName: statsInPlay.effectEnhancers)
    {
        auto enhancer = (*find_if(subject->myStatSystem.myStats.begin(),
                                  subject->myStatSystem.myStats.end(),
                                  IsStatNamed(statName)));
        enhanceValue += enhancer->currentValue;
    }
    for(auto statName: statsInPlay.effectDetractors)
    {
        auto detractor = (*find_if(object->myStatSystem.myStats.begin(),
                                   subject->myStatSystem.myStats.end(),
                                   IsStatNamed(statName)));
        detractValue += detractor->currentValue;
    }
    for(auto statName: statsInPlay.affectedStats)
    {
        auto affected = (*find_if(object->myStatSystem.myStats.begin(),
                                  subject->myStatSystem.myStats.end(),
                                  IsStatNamed(statName)));
        affected->currentValue -= max(enhanceValue-detractValue,1);
    }
    return true;
}
