#pragma once

#include "Forme.hpp"

#include <iostream>
#include <memory>
#include <vector>

class Canevas {
	private:
		std::vector<std::unique_ptr<Forme>> _formes;

	public:
		void ajouterDisque(int rayon);
		void ajouterRectangle(int largeur, int hauteur);
		double aireTotale() const;
		std::vector<Description> resume()const;

		void exportJSON(std::ostream & os, const std::string & what) const;
		void exportYAML(std::ostream & os, const std::string & what) const;

		void exportJSON2(std::ostream & os, const std::vector<Description>& ds) const;
		void exportYAML2(std::ostream & os, const std::vector<Description>& ds) const;

	private:
		void exportFormeJSON(std::ostream & os, const Forme * f) const;
		void exportFormeYAML(std::ostream & os, const Forme * f) const;

};

