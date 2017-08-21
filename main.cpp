#include "Elements/actionattack.h"
#include <iostream>
#include "Tests/catch.hpp"
#include "XML/loader.h"
#include "Console/consolehelper.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "thread"
#include "DemoComponents/demounit.h"
/*
void prepare(){
string name;
cout << "Unit's Name? : ";
cin >> name;
auto unit = Loader::loadUnit(name);
auto unit2 = Loader::loadUnit(name);
//Cambio
auto action = unit->mySkillSet.Actions.getAction("Attack");
action->perform(unit,unit2);
ConsoleHelper::unitPrint(unit2);
return;
}*/
void update(DemoUnit &subject,DemoUnit &object)
{
    ConsoleHelper::unitPrint(subject.unit);
    ConsoleHelper::unitPrint(object.unit);
    auto action = subject.unit->mySkillSet.getAction("Attack");
    auto subset = subject.unit->mySkillSet.getSubset("Special");
    auto actionInSubset = subset->getAction("Cape Swipe");
    action->perform(subject.unit,object.unit);
    actionInSubset->perform(subject.unit,subject.unit);
    ConsoleHelper::unitPrint(subject.unit);
    ConsoleHelper::unitPrint(object.unit);
    subject.sprite.move(subject.speed,0);
    object.sprite.move(object.speed,0);
    return;
}

int main()
{
    DemoUnit mario(Loader::loadUnit("Mario"));
    DemoUnit luigi(Loader::loadUnit("Luigi"));
    sf::RenderWindow window(sf::VideoMode(800, 600), "Demo 1");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                update(mario,luigi);
            }
        }
        window.clear(sf::Color::Black);
        window.draw(mario);
        window.draw(luigi);
        window.display();
    }
}

