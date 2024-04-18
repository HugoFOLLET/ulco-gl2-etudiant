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

TEST_CASE("Victoire rouge"){
	Jeu j;
	j.jouer(1,1);
	j.jouer(0,1);
	j.jouer(1,2);
	j.jouer(0,2);
	j.jouer(1,0);

	REQUIRE(j.getVictoire());
	REQUIRE(j.getStatus()==Status::RougeGagne);
}

TEST_CASE("Victoire vert"){
	Jeu j;
	j.jouer(1,1);
	j.jouer(1,0);
	j.jouer(1,2);
	j.jouer(2,0);
	j.jouer(2,2);
	j.jouer(0,0);

	REQUIRE(j.getVictoire());
	REQUIRE(j.getStatus()==Status::VertGagne);
}

TEST_CASE("Pas de victoire"){
	Jeu j;
	j.jouer(1,0);
	j.jouer(2,0);
	REQUIRE(!j.getVictoire());
}

TEST_CASE("Egalité"){
	Jeu j;
	j.jouer(1,1);

	j.jouer(2,2);
	j.jouer(0,0);


	j.jouer(0,2);
	j.jouer(2,0);

	j.jouer(1,0);
	j.jouer(1,2);

	j.jouer(0,1);
	j.jouer(2,1);

	REQUIRE(j.getVictoire());
	REQUIRE(j.getStatus()==Status::Egalite);
}


	// TODO


