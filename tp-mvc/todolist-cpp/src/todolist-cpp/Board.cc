#include <todolist-cpp/Board.hh>

void Board::addTodo(std::string desc){
	Task t {_nextId, desc};
	_todo.push_back(t);
	_nextId++;
}

bool Board::toDone(int id){
	for(auto it=_todo.begin(); it!=_todo.end(); it++){
		if(it->_id == id){
			auto p = _done.begin();
			p = _done.insert(p, {it->_id, it->_name});
			_todo.erase(it);
			return true;
		}
	}
	return false;
}