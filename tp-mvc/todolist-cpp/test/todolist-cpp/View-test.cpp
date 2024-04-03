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

TEST_CASE("test view 3"){
	Board b;
	b.addTodo("TODO");
	b.addTodo("TODO 2");
	b.toDone(1);
	std::string print="Todo:\n2. TODO 2\nDone:\n1. TODO\n";
	REQUIRE(printBoard(b) == print);
}