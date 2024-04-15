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


Status Jeu::getVictoire(){
	// On regarde les lignes horizontales et verticales
	int i=0;
	while (i<3){
		if(_plateau[i][0]==_plateau[i][1] && _plateau[i][1]==_plateau[i][2] && _plateau[i][0]!=Cell::Vide){
			return verifVictoire(i,0);
		}
		if(_plateau[0][i]==_plateau[1][i] && _plateau[1][i]==_plateau[2][i] && _plateau[0][i]!=Cell::Vide){
			return verifVictoire(0,i);
		}
		i=i+1;
	}

	// On regarde les lignes diagonales
	if(_plateau[0][0]==_plateau[1][1] && _plateau[1][1]==_plateau[2][2] && _plateau[1][1]!=Cell::Vide){
		return verifVictoire(1,1);
	}
	if(_plateau[0][2]==_plateau[1][1] && _plateau[2][0]==_plateau[1][1] && _plateau[1][1]!=Cell::Vide){
		return verifVictoire(1,1);
	}

	//On regarde si le plateau est rempli
	i=0;
	while(i<3){
		int j=0;
		while(j<3){
			if(getCell(i,j)==Cell::Vide){
				return getStatus();
			}
			j++;
		}
		i=i+1;
	}
	return Status::Egalite;
}

Status Jeu::verifVictoire(int i, int j){
	switch (getCell(i,j))
	{
	case Cell::Rouge:
		return Status::RougeGagne;
	case Cell::Vert:
		return Status::VertGagne;
	default:
		return Status::Egalite;
	}

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

