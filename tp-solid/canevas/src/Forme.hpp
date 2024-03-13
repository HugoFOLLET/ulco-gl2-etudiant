#pragma once
#include <math.h>

#include "Descriptible.hh"

class Forme : virtual public Descriptible {
	public:
		virtual ~Forme() = default;
		virtual double aire()const=0;
};

class Disque : public Forme {
	private:
		double _rayon;

	public:
		Disque(double rayon);

		Description toDescription()const override{
			Description desc;
			desc["name"]="Disque";
			desc["rayon"]=std::to_string(_rayon);
			return desc;
		}

		double aire()const override{
			return M_PI * (_rayon * _rayon);
		}
};

class Rectangle : public Forme {
	private:
		double _largeur;
		double _hauteur;

	public:
		Rectangle(double largeur, double hauteur);

		Description toDescription()const override{
			Description desc;
			desc["name"]="Rectangle";
			desc["largeur"]=std::to_string(_largeur);
			desc["hauteur"]=std::to_string(_hauteur);
			return desc;
		}

		double aire()const override{
			return _largeur*_hauteur;
		}
};

