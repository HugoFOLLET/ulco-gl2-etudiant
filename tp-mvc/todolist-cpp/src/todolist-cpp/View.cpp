#include <todolist-cpp/View.hpp>

std::string showTask(const Task& t){
	return std::to_string(t._id) + ". "+t._name;
}

std::string printBoard(const Board& b){
	std::string print="Todo:\n";
	for(auto it=b._todo.begin(); it!=b._todo.end(); it++){
		print=print+showTask(*it)+"\n";
	}
	print=print+"Done:\n";
	for(auto it=b._done.begin(); it!=b._done.end(); it++){
		print=print+showTask(*it)+"\n";
	}
	return print;
}

void showBoard(const Board& b, std::ostream& os){
	os << "Todo:\n";
	for(auto it=b._todo.begin(); it!=b._todo.end(); it++){
		os << showTask(*it) << std::endl;
	}
	os << "Done:\n";
	for(auto it=b._done.begin(); it!=b._done.end(); it++){
		os << showTask(*it) << std::endl;
	}
}