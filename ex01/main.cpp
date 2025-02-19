#include "RPN.hpp"

int main(int argc, char**argv) {
	if (argc == 2) {
		RPN cal;
		std::cout << cal.calculate(argv[1]) << std::endl;
	}
	else {
		std::cerr << "Error" << std::endl;
	}
}

/*
stackに入れる値の最大値はint
test
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"
./RPN "0 2 - 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * * 0 1 - /"
./RPN "0 2 - 8 8 8 8 8 8 8 8 8 8 * * * * * * * * * * 0 1 - "
./RPN "2 0 /"
./RPN "2 0    /"
./RPN "1 2    /"

./RPN "1 2 -" a
./RPN "1 a -"

./RPN ""
./RPN " "
./RPN "12 * 3"
./RPN "8 8 8 8 8 8 8 8 8 8 2 * * * * * * * * * *"
*/

//21 1 13 2 17 3 12 4 20 5 15 6 19 7 14 8 18 9 16 10 11