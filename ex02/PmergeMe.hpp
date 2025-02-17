#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <ctime>
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
		
		//vector
		void startMergeInsertSort_vec();
		std::vector<t_pair> mergeInsertSort_vec(std::vector<t_pair> array);
		void printVector(std::vector<int> vec);
		void print_pair_vector(std::vector<t_pair> pair_vec);
		std::vector<int> insert_sort_vec(std::vector<t_pair> new_array);
		std::vector<t_pair> sort_large_vec(std::vector<int>base, std::vector<t_pair> pair_array);
		int binary_pos_vec(int target, int end, std::vector<t_pair> array);
		//deque
		void printDeque(std::deque<int> deq);
		void startMergeInsertSort_deq();
		std::deque<t_pair> mergeInsertSort_deq(std::deque<t_pair> array);
		std::deque<int> insert_sort_deq(std::deque<t_pair> new_array);
		std::deque<t_pair> sort_large_deq(std::deque<int>base, std::deque<t_pair>pair_array);
		int binary_pos_deq(int target, int end, std::deque<t_pair> array);

		void check_vec_and_deq();

	private:
		std::vector<int> vec_array;
		std::deque<int> deq_array;
		static int jacob_stahal_seq[13];
		int	count_vec;
		int count_deq;
		clock_t start;
		clock_t end;

};

#endif