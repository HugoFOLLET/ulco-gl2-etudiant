#include <View.hh>

#include <catch2/catch.hpp>

TEST_CASE("test 1 view"){
    Board b;
    printBoard(b, std::cout);
    REQUIRE(true);
}