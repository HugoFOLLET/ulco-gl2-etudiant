#include "Tictactoe.hpp"

Jeu::Jeu() {
	raz();
}

Status Jeu::getStatus() const {
	return _statut;
}

Cell Jeu::getCell(int i, int j) const {
	if(i<0 or i>2 or j<0 or j>2){
		return Cell::Vide;
	}
	return _plateau[i][j];
}

std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
	int i=0;
	while(i<3){
		int j=0;
		while(j<3){
			switch(jeu.getCell(i,j)){
				case Cell::Rouge:
					os << "R ";
					break;
				case Cell::Vert:
					os << "V ";
					break;
				/*case Cell::Vide:
					os << ", ";
					break;*/
				default:
					os << ". ";
					break;
			}
			j++;
		}
		os << std::endl;
		i=i+1;
	}
	return os;
}

bool Jeu::jouer(int i, int j) {
	if(i<0 or i>2 or j<0 or j>2){
		return false;
	}

	if(getCell(i, j)==Cell::Vide){
		switch(getStatus()){
			case Status::RougeJoue:
				_plateau[i][j]=Cell::Rouge;
				_statut=Status::VertJoue;
				break;
			case Status::VertJoue:
				_plateau[i][j]=Cell::Vert;
				_statut=Status::RougeJoue;
				break;
			default:
				return false;
		}
	}
	return true;
}

void Jeu::raz(){
	int i=0;
	while(i<3){
		int j=0;
		while(j<3){
			_plateau[i][j]=Cell::Vide;
			j++;
		}
		i=i+1;
	}
	_statut=Status::RougeJoue;
}

