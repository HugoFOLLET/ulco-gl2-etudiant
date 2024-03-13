#pragma once

#include "NumBoard.hh"

#include <fstream>
#include <iostream>

class ReportFile{
	private:
		std::ofstream _ofs;
	public:
		ReportFile(const std::string& filename):_ofs(filename){}

		void report(Board& board) {
			for (const std::string & item : board.getItems())
				_ofs << item << std::endl;
			_ofs << std::endl;
		}
};