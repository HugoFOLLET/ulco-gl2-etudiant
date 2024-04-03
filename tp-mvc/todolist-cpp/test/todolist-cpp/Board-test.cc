#include <todolist-cpp/Board.hh>

#include <catch2/catch.hpp>

TEST_CASE("test 1 Board") {
	Board b;
	b.addTodo("TODO");
	auto it = b._todo.begin();
	REQUIRE(it->_id == 1);
	REQUIRE(it->_name == "TODO");
}

TEST_CASE("test 2 Board"){
	Board b;
	b.addTodo("TODO");
	b.addTodo("TODO 2");
	b.toDone(1);

	auto it = b._todo.begin();
	auto p = b._done.begin();

	REQUIRE(p->_id == 1);
	REQUIRE(p->_name == "TODO");
	REQUIRE(it->_id == 2);
	REQUIRE(it->_name == "TODO 2");
}

