#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE("test view 1"){
    Task t {1, "TODO"};
    REQUIRE(showTask(t) == "1. TODO");
}

TEST_CASE("test view 2"){
    Board b;
    b.addTodo("TODO");
    std::string print="Todo:\n1. TODO\nDone:\n";
    REQUIRE(printBoard(b) == print);
}