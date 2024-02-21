#include "Logger.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>

void Logger::addItem(Level l, const std::string & m, const std::string & temps) {
	_items.push_back({l,m,temps});
}

std::string Logger::reportByAdded() const {
	std::string text="";
	for(const Item &x : _items){
		text=text+std::get<2>(x)+" ";
		switch(std::get<0>(x)){
			case Level::Info:
				text=text+"[I]";
				break;
			case Level::Error:
				text=text+"[E]";
				break;
			case Level::Warning:
				text=text+"[W]";
				break;
		}
		text=text+" "+std::get<1>(x)+"\n";
	}
	return text;
}

std::string Logger::reportByLevel() const {
	std::string text="";

	for(const Item &x : _items){
		if(std::get<0>(x)==Level::Info){
				text=text+std::get<2>(x)+" [I] "+std::get<1>(x)+"\n";
		}
	}

	for(const Item &x : _items){
		if(std::get<0>(x)==Level::Error){
				text=text+std::get<2>(x)+" [E] "+std::get<1>(x)+"\n";
		}
	}

	for(const Item &x : _items){
		if(std::get<0>(x)==Level::Warning){
				text=text+std::get<2>(x)+" [W] "+std::get<1>(x)+"\n";
		}
	}
	return text;
}

