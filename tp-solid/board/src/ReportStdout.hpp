#pragma once

#include "Board.hpp"

#include <fstream>
#include <iostream>

class ReportStdout{
	public:
		void reportStdout(Board& board) {
			for (const std::string & item : board.getItems())
				std::cout << item << std::endl;
			std::cout << std::endl;
		}
};