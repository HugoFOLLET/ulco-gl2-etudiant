#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hh>

#include <iostream>

int main() {

	Board b;
	b.addTodo("TODO");
	b.addTodo("TODO 2");
	std::cout << printBoard(b) << std::endl;
	b.toDone(1);
	std::cout << printBoard(b) << std::endl;

	return 0;
}

