
#include "ReportStdout.hpp"
#include "ReportFile.hh"


void testBoard(Board & b) {
	std::cout << b.getTitle() << std::endl;
	b.add("item 1");
	b.add("item 2");
	ReportFile r("tmp.txt");
	r.report(b);
}

void testNumBoard(NumBoard& nb){
	std::cout << nb.getTitle() << std::endl;
	nb.add("item 3");
	nb.add("item 4");
	ReportStdout r;
	r.report(nb);
}

int main() {
	Board b1;
	testBoard(b1);

	NumBoard b2;
	testNumBoard(b2);
	testBoard(b2);

	return 0;
}

