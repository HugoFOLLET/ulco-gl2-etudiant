#include "Tictactoe.hpp"

Jeu::Jeu() {
	raz();
}

Status Jeu::getStatus() const {
	// TODO
	return Status::RougeJoue;
}

Cell Jeu::getCell(int i, int j) const {
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
	// TODO
	return false;
}

void Jeu::raz() {
	// TODO
}

