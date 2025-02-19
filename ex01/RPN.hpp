#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN {
	public:
		RPN();
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();
		int calculate(char *argv); 

	private:
		std::stack<long int> stack;
		void error_exit();
		
};

#endif