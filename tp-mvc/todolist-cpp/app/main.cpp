#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Board.hh>

#include <iostream>

int main() {

	Board b;
	std::string command;
	while(command!="quit"){
		std::cout << printBoard(b) << std::endl;
		std::getline(std::cin, command);
		
		std::string commande = command;
		std::string action = commande.substr(0, commande.find(" "));
		if(action=="add"){
			b.addTodo(commande.substr(commande.find(" ")+1, commande.length()-action.length()-1));
		}
		if(action=="done"){
			b.toDone(std::stoi(commande.substr(commande.find(" ")+1, commande.length()-action.length()-1)));
		}
		std::cout << std::endl;
	}

	return 0;
}

