#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hh>

#include <iostream>

int main() {

	Board b;
	Task t {1, "TOTO"};
	std::cout << t._name << std::endl;

	return 0;
}

