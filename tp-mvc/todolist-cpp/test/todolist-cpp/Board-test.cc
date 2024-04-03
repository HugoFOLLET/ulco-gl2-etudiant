#include <todolist-cpp/Board.hh>

#include <catch2/catch.hpp>

TEST_CASE("test 1 Board") {
    Board b;
    b.addTodo("TODO");
    auto it = b._todo.begin();
	REQUIRE(it->_id == 1);
    REQUIRE(it->_name == "TODO");
}

