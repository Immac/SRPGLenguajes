#include "actionattack.h"
bool ActionAttack::perform(std::shared_ptr<Unit> &subject, std::shared_ptr<Unit> &object, StatLists statsInPlay)
{
    int enhanceValue = 0;
    int detractValue = 0;
    for(auto statName: statsInPlay.effectEnhancers)
    {
        auto enhancer = (*std::find_if(subject->stats.begin(),subject->stats.end(),IsStatName(statName)));
        enhanceValue += enhancer->currentValue;
    }
    for(auto statName: statsInPlay.effectDetractors)
    {
        auto detractor = (*std::find_if(object->stats.begin(),subject->stats.end(),IsStatName(statName)));
        detractValue += detractor->currentValue;
    }
    for(auto statName: statsInPlay.affectedStats)
    {
        auto affected = (*std::find_if(object->stats.begin(),subject->stats.end(),IsStatName(statName)));
        affected->currentValue -= std::max(enhanceValue-detractValue,1);
    }
    return true;
}
