#include "RPN.hpp"

RPN::RPN(char **argv) {
	int i = 1;
	while(argv[i] != NULL) {
		std::string str(argv[i]);
		this -> stack.push(str);
		i++;
	}
}

RPN::RPN(const RPN& rhs) {
	this -> stack = rhs.stack;
}