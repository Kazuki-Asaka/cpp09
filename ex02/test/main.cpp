#include <iostream>
#include <vector>
#include <string>

int main(void) {
	std::vector<int> vec;
	
	vec.push_back(1);
	vec.push_back(2);

	for (std::vector<int>::iterator it = vec.begin(); it < vec.end();it++) {
		std::cout << *it << std::endl;
	}
	vec.erase(vec.begin() +1);
	for (std::vector<int>::iterator it = vec.begin(); it < vec.end();it++) {
		std::cout << *it << std::endl;
	}
}
