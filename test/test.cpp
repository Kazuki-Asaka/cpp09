#include <iostream>
#include <sstream>

int main() {
	std::stringstream ss("3\0");
	double f;
	ss >> f;
	if (ss.fail())
		std::cerr << "fail" << std::endl;
	else if (!ss.eof())
		std::cerr << "not EOF" << std::endl;
	else
		std::cout << "f: " << f << std::endl;
}