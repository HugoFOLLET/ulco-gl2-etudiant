#pragma once

#include "NumBoard.hh"

#include <fstream>
#include <iostream>

class ReportStdout{
	public:
		void report(Board& board) {
			for (const std::string & item : board.getItems())
				std::cout << item << std::endl;
			std::cout << std::endl;
		}
};