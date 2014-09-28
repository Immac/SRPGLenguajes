#include "demounit.h"
DemoUnit::DemoUnit(shared_ptr<Unit> aUnit):unit(aUnit)
{
    string texture = unit->getStat("SpriteSheet")->getText();
    if(spritesheet.loadFromFile(texture))
        sprite.setTexture(spritesheet);
    else
        throw 1;
    auto xPositionStat = unit->getStat("position_x");
    auto yPositionStat = unit->getStat("position_y");
    auto speedStat = unit->getStat("Speed");
    int xCoord = 0,
        yCoord = 0;
    if(xPositionStat->getId() != "Not Found")
    {
        xCoord = xPositionStat->getDefaultNumber();
    }
    if(yPositionStat->getId()!= "Not Found")
    {
        yCoord = yPositionStat->getDefaultNumber();
    }
    if(speedStat->getId()!= "Not Found")
    {
        speed = speedStat->getDefaultNumber();
    }

    sprite.setPosition(xCoord,yCoord);
}

void DemoUnit::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite,states);
}
