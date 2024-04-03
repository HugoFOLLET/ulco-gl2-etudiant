#include "View.hh"

void printBoard(const Board& b, std::ostream& os){
	board_t t;
	row_t r;
	int i=0,j;
	while(i<t.max_size()){
		j=0;
		while(j<r.max_size()){
			switch(b(i,j)){
				case Cell::Free:
					os << " ";
					break;
				case Cell::Goal:
					os << "G";
					break;
				case Cell::Wall:
					os << "X";
					break;
				default:
					os << "X";
					break;
			}
			j++;
		}
		os << std::endl;
		i=i+1;
	}
	os << std::endl;
}