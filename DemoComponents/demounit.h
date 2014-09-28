#ifndef DEMOUNIT_H
#define DEMOUNIT_H
#include "SFML/Graphics.hpp"
#include "Elements/unit.h"
class DemoUnit:public sf::Drawable
{
public:
    DemoUnit(shared_ptr<Unit> aUnit);
    shared_ptr<Unit> unit;
    sf::Texture spritesheet;
    sf::Sprite sprite;
    int speed;

    // Drawable interface
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif // DEMOUNIT_H
