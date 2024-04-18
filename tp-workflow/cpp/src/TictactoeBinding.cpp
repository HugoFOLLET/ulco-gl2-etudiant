#include "Tictactoe.hpp"

#include <pybind11/pybind11.h>

PYBIND11_MODULE(tictactoe, m) {
		
	pybind11::enum_<Cell>(m, "Cell")
		.value("Vide", Cell::Vide)
		.value("Rouge", Cell::Rouge)
		.value("Vert", Cell::Vert);


	pybind11::enum_<Status>(m, "Status")
		.value("RougeJoue", Status::RougeJoue)
		.value("VertJoue", Status::VertJoue)
		.value("RougeGagne", Status::RougeGagne)
		.value("VertGagne", Status::VertGagne)
		.value("Egalite", Status::Egalite)
		.value("Default", Status::Default);
	

	pybind11::class_<Jeu>(m, "Jeu")
		.def(pybind11::init<>())
		.def("getStatus", &Jeu::getStatus)
		.def("getCell", &Jeu::getCell)
		.def("getVictoire", &Jeu::getVictoire)
		.def("getJoueur", &Jeu::getJoueur)
		.def("afficherGagnant", &Jeu::afficherGagnant)
		.def("jouer", &Jeu::jouer)
		.def("raz", &Jeu::raz)
		.def("showStatus", &Jeu::showStringStatus);

}

