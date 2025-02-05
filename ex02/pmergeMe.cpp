#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc) {
	std::cout << "defult constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	// this -> small = rhs.small;
	this -> large = rhs.large;
	return (*this);
}

PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe destructor called" << std::endl;
}

int PmergeMe::add_str_num(char *argv) {
	std::string str(argv);
	std::stringstream ss(str);
	int i;

	ss >> i;
	if (ss.fail()||!ss.eof() || i < 0)
		return(-1);
	std::cerr << "add number " << i << std::endl;
	add_num(i);
	return (1);
}

void PmergeMe::add_num(int num) {
	large.push_back(num);
}

void PmergeMe::printVector() {
	const std::vector<int>::const_iterator end = test_table.end();
	for (std::vector<int>::const_iterator it = test_table.begin(); it != end; it++) {
		std::cout << "vector content : " << *it << std::endl;
	}
}

void PmergeMe::MergeInsertSort() {
	std::vector<int> small;

	if (this -> large.size() == 1)//インサートソート開始
	{

	}
	else {
		
	}
}

