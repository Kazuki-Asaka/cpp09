#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
	public:
		PmergeMe(std::string line);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator(const PmergeMe& rhs);
		~PmergeMe();
	private:
		//コンテナ*2
		PmergeMe();

};

#endif