#pragma once

#include "Reportable.hh"
#include "NumBoard.hh"

#include <fstream>
#include <iostream>

class ReportFile : public Reportable{
	private:
		std::ofstream _ofs;
	public:
		ReportFile(const std::string& filename):_ofs(filename){}

		void report(Board& board)override{
			for (const std::string & item : board.getItems())
				_ofs << item << std::endl;
			_ofs << std::endl;
		}
};