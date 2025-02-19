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