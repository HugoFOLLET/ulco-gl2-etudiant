
#include <Board.hpp>

#include <catch2/catch.hpp>

class BoardTest : public Board {
    public:
        BoardTest(int i, int j) : Board(i, j) {}
};

TEST_CASE( "init, 1" ) {
    Board b;
    REQUIRE( b.getI() == 0 );
    REQUIRE( b.getJ() == 0 );
}

TEST_CASE( "init, 2" ) {
    BoardTest b(1,2);
    REQUIRE( b.getI() == 1 );
    REQUIRE( b.getJ() == 2 );
}

TEST_CASE( "tryGoLeft, ok" ) {
    BoardTest b(7,3);
    b.tryGoLeft();
    REQUIRE( b.getI() == 7 );
    REQUIRE( b.getJ() == 2 );
}

TEST_CASE("tryGoRight, ok"){
    BoardTest b(5,1);
    b.tryGoRight();
    REQUIRE( b.getI() == 5 );
    REQUIRE( b.getJ() == 2 );
}

TEST_CASE("tryGoUp, ok"){
    BoardTest b(9,0);
    b.tryGoUp();
    REQUIRE(b.getI()==8);
    REQUIRE(b.getJ()==0);
}

TEST_CASE("tryGoDown, ok"){
    BoardTest b(8,0);
    b.tryGoDown();
    REQUIRE(b.getI()==9);
    REQUIRE(b.getJ()==0);
}

// TODO

