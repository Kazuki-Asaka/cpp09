#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
// #include <exception>

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
		void add_str_num(char *argv);
		void add_num(int num);
		void startMergeInsertSort();
		std::vector<t_pair> mergeInsertSort(std::vector<t_pair> array);
		void printVector(std::vector<int> vec);
		void print_pair_vector(std::vector<t_pair> pair_vec);
		std::vector<int> insert_sort(std::vector<t_pair> new_array);
		std::vector<t_pair> sort_large(std::vector<int>base, std::vector<t_pair> pair_array);
	private:
		std::vector<int> sequence;
		static int jacob_stahal_seq[13];
};

#endif