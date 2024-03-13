#pragma once

#include "Board.hpp"

#include <string>
#include <vector>

class Reportable {
	public:
		virtual ~Reportable(){};
		virtual void report(Board& board)=0;
};

