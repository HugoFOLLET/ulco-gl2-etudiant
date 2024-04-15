#include "Tictactoe.hpp"
#include <sstream>

#include <catch2/catch.hpp>

TEST_CASE("Test getCell") { 
	Jeu j;
	j.jouer(1,1);
	j.jouer(2,2);
	REQUIRE(j.getCell(0,0)==Cell::Vide);
	REQUIRE(j.getCell(1,1)==Cell::Rouge);
	REQUIRE(j.getCell(2,2)==Cell::Vert);
}

TEST_CASE("Test affichange"){
	Jeu j;
	std::stringstream out;
	out << j;
	REQUIRE(out.str()==". . . \n. . . \n. . . \n");
}

TEST_CASE("Test jouer"){
	Jeu j;
	REQUIRE(j.getStatus()==Status::RougeJoue);
	REQUIRE(j.jouer(1,1));
	REQUIRE(j.getStatus()==Status::VertJoue);
	REQUIRE(j.jouer(2,2));
	REQUIRE(j.getStatus()==Status::RougeJoue);
}


	// TODO


