#include "Tictactoe.hpp"

using namespace std;

int main() {
	Jeu jeu;
	int i,j;
	string output,out_i,out_j;
	while(!jeu.getVictoire()){
		cout << jeu << endl;
		cout << "Entrez votre coup joueur " << jeu.getJoueur() << " : <ligne colonne>" << endl;
		getline(cin,output);
		out_i=output.substr(0, output.find(' '));
		out_j=output.substr(output.find(' ')+1);
		i=stoi(out_i);
		j=stoi(out_j);
		cout << "i : " << i << " j : " << j << endl;
		while(!jeu.jouer(i,j)){
			cout << "Erreur de case : entrez de bonnes coordonnées" << endl;
			cout << jeu << endl;
			cout << "Entrez votre coup joueur " << jeu.getJoueur() << " : <ligne colonne>" << endl;
			getline(cin,output);
			out_i=output.substr(0, output.find(' '));
			out_j=output.substr(output.find(' ')+1);
			i=stoi(out_i);
			j=stoi(out_j);
			cout << "i : " << i << " j : " << j << endl;
		}
	}
	jeu.afficherGagnant(cout);

	return 0;
}

