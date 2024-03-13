#pragma once

#include "Titleable.hh"

#include <fstream>
#include <iostream>

class Board : public Titleable{
	private:
		std::vector<std::string> _tasks;

	public:
		Board(){}

		void add(const std::string & t){
			_tasks.push_back(t);
		}

		std::vector<std::string> getItems()const{
			return _tasks;
		}

		virtual std::string getTitle()const override{
			return "Board";
		}
};

