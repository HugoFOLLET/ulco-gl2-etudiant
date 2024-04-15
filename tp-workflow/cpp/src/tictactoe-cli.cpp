#include "Tictactoe.hpp"

using namespace std;

int main() {
	Jeu jeu;
	int i,j;
	string output,out_i,out_j;
	while(jeu.getVictoire()==jeu.getStatus()){
		cout << jeu << endl;
		cout << "Entrez votre coup joueur " << jeu.getJoueur() << " : <ligne colonne>" << endl;
		getline(cin,output);
		out_i=output.substr(0, output.find(' '));
		out_j=output.substr(output.find(' ')+1);
		i=stoi(out_i);
		j=stoi(out_j);
		cout << "i : " << i << " j : " << j << endl;
		jeu.jouer(i,j);
	}

	jeu.afficherGagnant(cout);

	return 0;
}

