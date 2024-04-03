#pragma once

#include <todolist-cpp/Task.hpp>

#include <list>

class Board{
	private:
		int _nextId;
	
	public:
		std::list <Task> _todo;
		std::list <Task> _done;
		
		Board():_nextId(1){}

		void addTodo(std::string desc){
			Task t {_nextId, desc};
			auto it = _todo.begin();
			it = _todo.insert(it, t);
			_nextId++;
		}

};