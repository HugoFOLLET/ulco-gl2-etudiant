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

std::string Jeu::getJoueur(){
	switch(getStatus()){
		case Status::RougeJoue:
			return "Rouge";
		case Status::VertJoue:
			return "Vert";
		default:
			return "Default";
	}
}

void Jeu::afficherGagnant(std::ostream& os){
	switch(getStatus()){
		case Status::RougeGagne:
			os << "Le joueur rouge a gagné !" << std::endl;
			break;
		case Status::VertGagne:
			os << "Le joueur vert a gagné !" << std::endl;
			break;
		case Status::Egalite:
			os << "Egalité pour les deux joueurs" << std::endl;
			break;
		default:
			os << "Jeu non fini" << std::endl;
			break;
	}
}


bool Jeu::getVictoire(){
	// On regarde les lignes horizontales et verticales
	int i=0;
	while (i<3){
		if(_plateau[i][0]==_plateau[i][1] && _plateau[i][1]==_plateau[i][2] && _plateau[i][0]!=Cell::Vide){
			Status victoire=verifVictoire(i,0);
			return victoire==Status::RougeGagne || victoire==Status::VertGagne;
		}
		if(_plateau[0][i]==_plateau[1][i] && _plateau[1][i]==_plateau[2][i] && _plateau[0][i]!=Cell::Vide){
			Status victoire=verifVictoire(0,i);
			return victoire==Status::RougeGagne || victoire==Status::VertGagne;
		}
		i=i+1;
	}

	// On regarde les lignes diagonales
	if(_plateau[0][0]==_plateau[1][1] && _plateau[1][1]==_plateau[2][2] && _plateau[1][1]!=Cell::Vide){
		Status victoire = verifVictoire(1,1);
		return victoire==Status::RougeGagne || victoire==Status::VertGagne;
	}
	if(_plateau[0][2]==_plateau[1][1] && _plateau[2][0]==_plateau[1][1] && _plateau[1][1]!=Cell::Vide){
		Status victoire = verifVictoire(1,1);
		return victoire==Status::RougeGagne || victoire==Status::VertGagne;
	}

	//On regarde si le plateau est rempli
	i=0;
	while(i<3){
		int j=0;
		while(j<3){
			if(getCell(i,j)==Cell::Vide){	//Si une case n'est pas vide, on retourne faux
				return false;
			}
			j++;
		}
		i=i+1;
	}
	//Sinon, c'est l'égalité
	_statut=Status::Egalite;
	return true;
}

Status Jeu::verifVictoire(int i, int j){
	switch (getCell(i,j)){
		case Cell::Rouge:
			_statut=Status::RougeGagne;
			return Status::RougeGagne;
		case Cell::Vert:
			_statut=Status::VertGagne;
			return Status::VertGagne;
		default:
			_statut=Status::Egalite;
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
	}else{
		return false;
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


std::string Jeu::showStringStatus(Status statut){
	std::string msg;
	switch(statut){
		case Status::Default:
			msg="Défault";
			break;
		case Status::Egalite:
			msg="Egalité";
			break;
		case Status::RougeGagne:
			msg="Rouge Gagne";
			break;
		case Status::VertGagne:
			msg="Vert Gagne";
			break;
		case Status::RougeJoue:
			msg="Tour de Rouge";
			break;
		case Status::VertJoue:
			msg="Tour de Vert";
			break;
	}
	return msg;
}


void Jeu::showStatus(std::ostream& os, Status statut){
	switch(statut){
		case Status::Default:
			os << "Défault";
			break;
		case Status::Egalite:
			os << "Egalité";
			break;
		case Status::RougeGagne:
			os << "Rouge Gagne";
			break;
		case Status::VertGagne:
			os << "Vert Gagne";
			break;
		case Status::RougeJoue:
			os << "Tour de Rouge";
			break;
		case Status::VertJoue:
			os << "Tour de Vert";
			break;
	}
	os << std::endl;
}