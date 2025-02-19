#include "RPN.hpp"

RPN::RPN() {
	std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(const RPN& rhs) {
	// this -> stack = rhs.stack;
	*this = rhs;
}

RPN& RPN::operator=(const RPN& rhs) {
	this -> stack = rhs.stack;
	return(*this);
}

RPN::~RPN() {
	std::cout << "RPN destructor called" << std::endl;
}

int RPN::calculate(char *argv) {
	std::stringstream ss(argv);
	long int x1;
	long int x2;
	while(!ss.fail() && !ss.eof()) {
		std::string str;
		ss >> str;
		if (str == "+" || str == "-" || str == "*" || str == "/") {
			long int result;
			if (stack.size() < 2)
				error_exit();
			x1 = stack.top();
			stack.pop();
			x2 = stack.top();
			stack.pop();
			if (str == "+"){
				result = static_cast<long int>(x2) + static_cast<long int>(x1);
			}
			else if (str == "-") {
				result = static_cast<long int>(x2) - static_cast<long int>(x1);
			}
			else if (str == "*") {
				result = static_cast<long int>(x2) * static_cast<long int>(x1);
			}
			else {
				if (x1 == 0)
					error_exit();
				result = static_cast<long int>(x2) / static_cast<long int>(x1);
			}
			check_max_min(result);
			stack.push(static_cast<int>(result));
		}
		else {
			std::stringstream ss1(str);
			int num;
			ss1 >> num;
			if (ss1.fail() || !ss1.eof())
				error_exit();
			if (num < 0 || 9 < num)
				error_exit();
			stack.push(num);
		}
	}
	if (stack.size() != 1)
		error_exit();
	return (stack.top());
}

void RPN::error_exit() {
	std::cerr << "Error" << std::endl;
	std::exit(1); 
}

void RPN::check_max_min(long int result) {
	// std::cout << "result : " << result << std::endl;
	if (result < INT_MIN || INT_MAX < result)
		error_exit();
}