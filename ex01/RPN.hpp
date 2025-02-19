#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <climits>

class RPN {
	public:
		RPN();
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();
		int calculate(char *argv); 
		void check_max_min(long int result);
	private:
		std::stack<int> stack;
		void error_exit();
};

#endif