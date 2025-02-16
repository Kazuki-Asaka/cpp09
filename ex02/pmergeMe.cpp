#include "PmergeMe.hpp"

int PmergeMe::jacob_stahal_seq[13] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462};

PmergeMe::PmergeMe(){
	// std::cout << "PmergeMe default constructor called" << std::endl;
	count_vec = 0;
	count_deq = 0;
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	this -> vec_array = rhs.vec_array;
	this -> deq_array = rhs.deq_array;
	this -> count_vec = rhs.count_vec;
	this -> count_deq = rhs.count_deq;
	return(*this);
}

PmergeMe::~PmergeMe() {
	// std::cout << "Pmerge destructor called" << std::endl;
}

void PmergeMe::printVector(std::vector<int> vec) {
	const std::vector<int>::const_iterator end = vec.end();
	// std::cout << "content : " ;
	for (std::vector<int>::const_iterator it = vec.begin(); it != end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::print_pair_vector(std::vector<t_pair> pair_vec) {
	const std::vector<t_pair>::const_iterator end = pair_vec.end();
	std::cout << "large : ";
	for (std::vector<t_pair>::const_iterator it = pair_vec.begin(); it != end; it++) {
		std::cout <<  it -> large << " ";
	}
	std::cout << std::endl;
	std::cout << "small : ";
	for (std::vector<t_pair>::const_iterator it = pair_vec.begin(); it != end; it++) {
		std::cout <<  it -> small << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::add_str_num(char *argv) {
	std::string	str_int(argv);
	std::stringstream ss(str_int);

	int i;
	ss >> i;
	if (ss.fail() || !ss.eof()) {
		std::cerr << "input argv error" << std::endl;
		std::exit(1);
	}
	else
		add_num(i);
}

void PmergeMe::add_num(int num) {
	if (num < 0) {
		std::cerr << "this is negative number" << std::endl;
		std::exit(1);
	}
	else {
		this -> vec_array.push_back(num);
		this -> deq_array.push_back(num);
	}
}

void PmergeMe::startMergeInsertSort_vec() {
	std::vector<t_pair> pair_array;
	this -> start = clock();
	for (int i = 0; i + 1 <  static_cast<int>(vec_array.size()); i+=2) {
		t_pair tmp;
		if (vec_array[i] < vec_array[i + 1]) {
			tmp.small = vec_array[i];
			tmp.large = vec_array[i + 1];
		}
		else {
			tmp.small = vec_array[i + 1];
			tmp.large = vec_array[i];
		}
		pair_array.push_back(tmp);
		this -> count_vec++;
	}
	if (vec_array.size() % 2 == 1) {
		t_pair tmp;
		tmp.large = -1;
		tmp.small = vec_array[vec_array.size() - 1];
		pair_array.push_back(tmp);
	}
	std::cout << "Before:  ";
	printVector(this -> vec_array);
	std::vector<t_pair> test = mergeInsertSort_vec(pair_array);
	this->vec_array = insert_sort_vec(test);
	std::cout << "After:  " ;
	printVector(this -> vec_array);
	this -> end = clock();
	std::cout << "Time to process a range of   " << vec_array.size() << " elements with std::[vector] : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * static_cast<double>(1000000) << " us" << std::endl;
	std::cout << "count_vec : " <<this -> count_vec << std::endl;
}

std::vector<t_pair> PmergeMe::mergeInsertSort_vec(std::vector<t_pair> array) {
	std::vector<t_pair> new_array;
	int array_size = 0;
	// std::cout << "---------" << std::endl;
	// print_pair_vector(array);
	for (int i = 0; i < static_cast<int>(array.size()); i++) {
		if (array[i].large == -1)
			break;
		array_size++;
	}
	if (array_size == 1)
		return (array);
	else {
		for (int i = 0; i + 1 < array_size; i+=2) {
			t_pair tmp;
			if (array[i].large < array[i + 1].large) {
				tmp.small = array[i].large;
				tmp.large = array[i + 1].large;
			}
			else {
				tmp.small = array[i + 1].large;
				tmp.large = array[i].large;
			}
			this -> count_vec++;
			new_array.push_back(tmp);
		}
		if (array_size % 2 == 1) {
			t_pair tmp;
			tmp.small = array[array_size - 1].large;
			tmp.large = -1;
			new_array.push_back(tmp);
		}
		std::vector<t_pair> merge_array = mergeInsertSort_vec(new_array);
		std::vector<int> sorted = insert_sort_vec(merge_array);
		merge_array = sort_large_vec(sorted, array);
		return (merge_array);
	}
}

std::vector<int> PmergeMe::insert_sort_vec(std::vector<t_pair> new_array) {
	std::vector<int> sorted;
	std::vector<int> small_array;
	for (int i = 0; i < static_cast<int>(new_array.size()); i++) {
		if (new_array[i].large == -1)
			break ;
		sorted.push_back(new_array[i].large);
	}
	for (int i = 0; i < static_cast<int>(new_array.size()); i++) {
		if (new_array[i].small == -1)
			break ;
		small_array.push_back(new_array[i].small);
	}
	if (small_array.size() == 0)
		return (sorted);
	std::vector<int>::iterator sorted_head = sorted.begin();
	std::vector<int>::iterator small_array_head = small_array.begin();	
	sorted.insert(sorted_head, *small_array_head);
	small_array.erase(small_array_head);
	if (small_array.size() == 0)
		return (sorted);
	else {
		for (int i = 0; i < 16; i++) {
			int line = jacob_stahal_seq[i] - 1;
			if (small_array.size() == 0)
				break;
			if (static_cast<int>(small_array.size()) < jacob_stahal_seq[i])
				line = small_array.size() - 1;
			for (int j = line; j >= 0; j -= 1) {
				for (int k = 0; k < static_cast<int>(sorted.size());k++) {
					this -> count_vec++;
					if (small_array[j] <= sorted[k]) {
						sorted.insert(sorted.begin() + k, small_array[j]);
						break ;
					}
					else if (k == static_cast<int>(sorted.size() - 1)) {
						sorted.push_back(small_array[line]);
						break ;
					}
					else if (sorted[k] <= small_array[j] && small_array[j] <= sorted[k + 1]) {
						sorted.insert(sorted.begin() + k + 1, small_array[j]);
						// this -> count_vec++;
						break ;
					}
				}
			}
			small_array.erase(small_array.begin(), small_array.begin() + line + 1);
		}
		return (sorted);
	}
}

std::vector<t_pair> PmergeMe::sort_large_vec(std::vector<int>base, std::vector<t_pair>pair_array) {
	std::vector<t_pair> new_array;
	
	for (int i = 0; i < static_cast<int>(base.size()); i++) {
		for (int j = 0; j < static_cast<int>(pair_array.size()); j++) {
			if (base[i] == pair_array[j].large) {
				new_array.push_back(pair_array[j]);
				pair_array.erase(pair_array.begin() + j);
				break ;
			}
		}
	}
	for (int i = 0; i < static_cast<int>(pair_array.size()); i++) {
		new_array.push_back(pair_array[i]);
	}
	return (new_array);
}

/*
dequeでの実装
*/

void PmergeMe::printDeque(std::deque<int> deq) {
	const std::deque<int>::const_iterator end = deq.end();
	// std::cout << "content : " ;
	for (std::deque<int>::const_iterator it = deq.begin(); it != end; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::startMergeInsertSort_deq() {
	this -> start = clock();
	std::deque<t_pair> pair_array;
	for (int i = 0; i + 1 <  static_cast<int>(deq_array.size()); i+=2) {
		t_pair tmp;
		if (deq_array[i] < deq_array[i + 1]) {
			tmp.small = deq_array[i];
			tmp.large = deq_array[i + 1];
		}
		else {
			tmp.small = deq_array[i + 1];
			tmp.large = deq_array[i];
		}
		pair_array.push_back(tmp);
		this -> count_deq++;
	}
	if (deq_array.size() % 2 == 1) {
		t_pair tmp;
		tmp.large = -1;
		tmp.small = deq_array[deq_array.size() - 1];
		pair_array.push_back(tmp);
	}
	// std::cout << "Before: ";
	// printDeque(this -> deq_array);
	std::deque<t_pair> test = mergeInsertSort_deq(pair_array);
	this->deq_array = insert_sort_deq(test);
	// std::cout << "After: ";
	// printDeque(this -> deq_array);
	// std::cout << "count_deq : " <<this -> count_deq << std::endl;
	this -> end = clock();
	std::cout << "Time to process a range of   " << vec_array.size() << " elements with std::[deque] : " << static_cast<double>(end - start) / CLOCKS_PER_SEC * static_cast<double>(1000000) << " us" << std::endl;
}

std::deque<t_pair> PmergeMe::mergeInsertSort_deq(std::deque<t_pair> array) {
	std::deque<t_pair> new_array;
	int array_size = 0;
	// std::cout << "---------" << std::endl;
	// print_pair_vector(array);
	for (int i = 0; i < static_cast<int>(array.size()); i++) {
		if (array[i].large == -1)
			break;
		array_size++;
	}
	if (array_size == 1)
		return (array);
	else {
		for (int i = 0; i + 1 < array_size; i+=2) {
			t_pair tmp;
			if (array[i].large < array[i + 1].large) {
				tmp.small = array[i].large;
				tmp.large = array[i + 1].large;
			}
			else {
				tmp.small = array[i + 1].large;
				tmp.large = array[i].large;
			}
			this -> count_deq++;
			new_array.push_back(tmp);
		}
		if (array_size % 2 == 1) {
			t_pair tmp;
			tmp.small = array[array_size - 1].large;
			tmp.large = -1;
			new_array.push_back(tmp);
		}
		std::deque<t_pair> merge_array = mergeInsertSort_deq(new_array);
		std::deque<int> sorted = insert_sort_deq(merge_array);
		merge_array = sort_large_deq(sorted, array);
		return (merge_array);
	}
}

std::deque<int> PmergeMe::insert_sort_deq(std::deque<t_pair> new_array) {
	std::deque<int> sorted;
	std::deque<int> small_array;
	for (int i = 0; i < static_cast<int>(new_array.size()); i++) {
		if (new_array[i].large == -1)
			break ;
		sorted.push_back(new_array[i].large);
	}
	for (int i = 0; i < static_cast<int>(new_array.size()); i++) {
		if (new_array[i].small == -1)
			break ;
		small_array.push_back(new_array[i].small);
	}
	if (small_array.size() == 0)
		return (sorted);
	std::deque<int>::iterator sorted_head = sorted.begin();
	std::deque<int>::iterator small_array_head = small_array.begin();	
	sorted.insert(sorted_head, *small_array_head);
	small_array.erase(small_array_head);
	if (small_array.size() == 0)
		return (sorted);
	else {
		for (int i = 0; i < 16; i++) {
			int line = jacob_stahal_seq[i] - 1;
			if (small_array.size() == 0)
				break;
			if (static_cast<int>(small_array.size()) < jacob_stahal_seq[i])
				line = small_array.size() - 1;
			for (int j = line; j >= 0; j -= 1) {
				for (int k = 0; k < static_cast<int>(sorted.size());k++) {
					this -> count_deq++;
					if (small_array[j] <= sorted[k]) {
						sorted.insert(sorted.begin() + k, small_array[j]);
						break ;
					}
					else if (k == static_cast<int>(sorted.size() - 1)) {
						sorted.push_back(small_array[line]);
						break ;
					}
					else if (sorted[k] <= small_array[j] && small_array[j] <= sorted[k + 1]) {
						sorted.insert(sorted.begin() + k + 1, small_array[j]);
						break ;
					}
				}
			}
			small_array.erase(small_array.begin(), small_array.begin() + line + 1);
		}
		return (sorted);
	}
}

std::deque<t_pair> PmergeMe::sort_large_deq(std::deque<int>base, std::deque<t_pair>pair_array) {
	std::deque<t_pair> new_array;
	
	for (int i = 0; i < static_cast<int>(base.size()); i++) {
		for (int j = 0; j < static_cast<int>(pair_array.size()); j++) {
			if (base[i] == pair_array[j].large) {
				new_array.push_back(pair_array[j]);
				pair_array.erase(pair_array.begin() + j);
				break ;
			}
		}
	}
	for (int i = 0; i < static_cast<int>(pair_array.size()); i++) {
		new_array.push_back(pair_array[i]);
	}
	return (new_array);
}


//ソートする要素数について