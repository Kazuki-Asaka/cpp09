#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

typedef struct s_pair {
	int small;
	int large;
} t_pair;

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();
		int add_str_num(char *argv);
		void add_num(int num);
		void MergeInsertSort();
		void printVector();
	private:
		// std::vector<int> small;
		std::vector<int> large;
};

#endif