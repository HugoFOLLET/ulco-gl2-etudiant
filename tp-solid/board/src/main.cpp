#include "Titleable.hh"
#include "ReportStdout.hpp"
#include "ReportFile.hh"


void testBoard(Board & b, Reportable& r) {
	std::cout << b.getTitle() << std::endl;
	b.add("item 1");
	b.add("item 2");
	r.report(b);
}

void testNumBoard(NumBoard& nb, Reportable& r){
	std::cout << nb.getTitle() << std::endl;
	nb.add("item 3");
	nb.add("item 4");
	r.report(nb);
}

int main() {
	Board b1;
	NumBoard b2;
	ReportFile rf("text.txt");
	ReportStdout rs;

	testBoard(b1,rs);
	testNumBoard(b2,rf);
	testBoard(b2,rs);

	return 0;
}

