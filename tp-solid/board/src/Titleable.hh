#pragma once

#include <string>
#include <vector>

class Titleable {
	public:
		virtual ~Titleable(){};
		virtual std::string getTitle() const = 0;
};

