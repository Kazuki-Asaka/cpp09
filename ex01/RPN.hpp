#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN {
	public:
		RPN(char **argv);
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();
		int calculate(); 
	private:
		RPN();
		std::stack<std::string> stack;
		
};

#endif