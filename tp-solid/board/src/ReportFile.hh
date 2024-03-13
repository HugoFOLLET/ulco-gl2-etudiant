#pragma once

#include "Board.hpp"

#include <fstream>
#include <iostream>

class ReportFile{
	public:
		void reportFile(Board& board) {
			for (const std::string & item : board.getItems())
				std::cout << item << std::endl;
			std::cout << std::endl;
		}
};