#pragma once

#include "Board.hpp"

#include <fstream>
#include <iostream>

class NumBoard : public Board{
	private:
		int compt;
	public:
		NumBoard():Board(),compt(1){}

		void add(const std::string& t){
			Board::add(std::to_string(compt)+". "+t);
			compt++;
		}

		std::string getTitle()const override{
			return "NumBoard";
		}
		
};