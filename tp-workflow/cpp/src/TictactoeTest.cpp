#include "Tictactoe.hpp"
#include <sstream>

#include <catch2/catch.hpp>

TEST_CASE("Test getCell") { 
	Jeu j;
	REQUIRE(j.getCell(0,0)==Cell::Vide);
}

TEST_CASE("Test affichange"){
	Jeu j;
	std::stringstream out;
	out << j;
	REQUIRE(out.str()==". . . \n. . . \n. . . \n");
}


	// TODO


