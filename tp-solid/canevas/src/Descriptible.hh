#pragma once

#include <iostream>
#include <map>

typedef std::map<std::string, std::string> Description;

class Descriptible{
	public:
		virtual ~Descriptible(){};
		virtual Description toDescription()const =0;
};