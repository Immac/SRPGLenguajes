#include "Elements/actionattack.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "Tests/catch.hpp"
#include "Tests/test.h"
void text()
{
    auto myUnit = Test::newUnit();
    auto yourUnit = Test::newUnit();
}

TEST_CASE( "vectors can be sized and reszed", "[vector]" ) {

    std::vector<int> v( 5 );

    REQUIRE( v.size() == 5 );
    REQUIRE( v.capacity() >= 5 );

    SECTION( "resizing bigger changes size and capacity" ) {
        v.resize( 10 );

        REQUIRE( v.size() == 10 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "resizing smaller changes size but not capacity" ) {
        v.resize( 0 );

        REQUIRE( v.size() == 0 );
        REQUIRE( v.capacity() >= 5 );
    }
    SECTION( "reserving bigger changes capacity but not size" ) {
        v.reserve( 10 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 10 );
    }
    SECTION( "reserving smaller does not change size or capacity" ) {
        v.reserve( 0 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );
    }
}

//std::shared_ptr<Board> localNewBoard = Test::newBoard();
//auto attackAction = ActionAttack(std::string("Attack"));
//auto panel1 = Test::newPanel(0,0);
//auto panel2 = Test::newPanel(0,1);
//auto myUnit = Test::newUnit();
//auto yourUnit = Test::newUnit();
//for(int i = 0 ; i < 8 ; i++)
//   attackAction.perform(myUnit,yourUnit,Test::AtkDefHpInPlay());
//if(panel1->recieveUnit(std::move(myUnit)))
//   std::cout << "Panel 1 recieved";
//if(panel1->giveMyUnitTo(panel2))
//   std::cout << "Panel 2 recieved";
//if(panel2->giveMyUnitTo(panel1))
//   std::cout << "Panel 1 recieved";
//attackAction.perform(myUnit,yourUnit,Test::AtkDefHpInPlay());
//attackAction.perform(myUnit,yourUnit,Test::AtkDefHpInPlay());
//attackAction.perform(yourUnit,myUnit,Test::AtkDefHpInPlay());
