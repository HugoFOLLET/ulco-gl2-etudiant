#pragma once

#include <todolist-cpp/Task.hpp>

#include <list>
#include <iostream>

class Board{
	private:
		int _nextId;
	
	public:
		std::list <Task> _todo;
		std::list <Task> _done;
		
		Board():_nextId(1){}

		void addTodo(std::string desc);
		bool toDone(int id);

};