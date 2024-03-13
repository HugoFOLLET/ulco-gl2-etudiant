#pragma once

#include "Reportable.hh"
#include "NumBoard.hh"

#include <fstream>
#include <iostream>

class ReportStdout : public Reportable{
	public:
		void report(Board& board)override{
			for (const std::string & item : board.getItems())
				std::cout << item << std::endl;
			std::cout << std::endl;
		}
};