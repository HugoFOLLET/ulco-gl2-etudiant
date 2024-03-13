#include "Canevas.hpp"

#include <cmath>
#include <numeric>

void Canevas::ajouterDisque(int rayon) {
	_formes.push_back(std::make_unique<Disque>(rayon));
}

void Canevas::ajouterRectangle(int largeur, int hauteur) {
	_formes.push_back(std::make_unique<Rectangle>(largeur, hauteur));
}

double Canevas::aireTotale() const {
	double res = 0.0;
	for (const auto & f : _formes)
		res += f->aire();
	return res;
}

void Canevas::exportFormeYAML(std::ostream & os, const Forme * f) const {
	Description desc=f->toDescription();
	auto name = desc.find("name");
	os << "- " << name->first << ": \"" << name->second << "\"\n";
	for(auto it=desc.begin(); it!=desc.end(); ++it){
		if(it->first!="name"){
			os << "  " << it->first << ": \"" << it->second << "\"\n";
		}
	}
}

void Canevas::exportYAML(std::ostream & os, const std::string & what) const {
	if (what == "resume") {
		os << "- name: \"Canevas\"\n";
		os << "  aireTotale: \"" << aireTotale() << "\"\n";;
		return;
	}

	if (what == "descriptions") {
		for (const auto & f : _formes)
			exportFormeYAML(os, f.get());
		return;
	}
}

void Canevas::exportYAML2(std::ostream& os, const std::vector<Description>& ds)const{

}


void Canevas::exportFormeJSON(std::ostream & os, const Forme * f) const {

	Description desc=f->toDescription();
	auto name = desc.find("name");
	os << "  {\n";
	os << "    \"" << name->first << "\": \"" << name->second << "\",\n";

	int i=2;

	for(auto it=desc.begin(); it!=desc.end(); ++it){
		if(it->first!="name"){
			os << "    \"" << it->first << "\": \"" << it->second << "\"";
			if(i<desc.size()){
				os << ",";
			}
			os << "\n";
		}
		
		i=i+1;
		
	}
	os << "  }";
	return;
}

void Canevas::exportJSON(std::ostream & os, const std::string & what) const {
	if (what == "resume") {
		os << "[\n";
		os << "  {\n";
		os << "    \"name\": \"Canevas\",\n";
		os << "    \"aireTotale\": \"" << aireTotale() << "\"\n";;
		os << "  }\n";
		os << "]\n";
		return;
	}

	if (what == "descriptions") {
		os << "[\n";
		if (not _formes.empty()) {
			auto iter = _formes.begin();
			exportFormeJSON(os, iter->get());
			++iter;
			for ( ; iter!=_formes.end(); ++iter) {
				os << ",\n";
				exportFormeJSON(os, iter->get());
			}
		}
		os << "\n]\n";
		return;
	}
}


