#include "PmergeMe.hpp"

int PmergeMe::jacob_stahal_seq[13] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462};

PmergeMe::PmergeMe(){
	std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	this -> sequence = rhs.sequence;
	return(*this);
}

PmergeMe::~PmergeMe() {
	std::cout << "Pmerge destructor called" << std::endl;
}

void PmergeMe::printVector(std::vector<int> vec) {
	const std::vector<int>::const_iterator end = vec.end();
	std::cout << "content : " ;
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
	else
		this -> sequence.push_back(num);
}

void PmergeMe::startMergeInsertSort() {
	std::vector<t_pair> pair_array;
	for (int i = 0; i + 1 <  static_cast<int>(sequence.size()); i+=2) {
		t_pair tmp;
		if (sequence[i] < sequence[i + 1]) {
			tmp.small = sequence[i];
			tmp.large = sequence[i + 1];
		}
		else {
			tmp.small = sequence[i + 1];
			tmp.large = sequence[i];
		}
		pair_array.push_back(tmp);
	}
	if (sequence.size() % 2 == 1) {
		t_pair tmp;
		tmp.large = -1;
		tmp.small = sequence[sequence.size() - 1];
		pair_array.push_back(tmp);
	}
	// print_pair_vector(pair_array);
	std::vector<t_pair> test = mergeInsertSort(pair_array);
	// print_pair_vector(test);
	this->sequence = insert_sort(test);
	printVector(this -> sequence);
}

std::vector<t_pair> PmergeMe::mergeInsertSort(std::vector<t_pair> array) {
	std::vector<t_pair> new_array;
	int array_size = 0;
	std::cout << "---------" << std::endl;
	print_pair_vector(array);
	for (int i = 0; i < static_cast<int>(array.size()); i++) {
		if (array[i].large == -1)
			break;
		array_size++;
	}
	std::cout << "array_size : " << array_size << std::endl;;
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
			new_array.push_back(tmp);
		}
		if (array_size % 2 == 1) {
			t_pair tmp;
			tmp.small = array[array_size - 1].large;
			tmp.large = -1;
			new_array.push_back(tmp);
		}
		std::vector<t_pair> merge_array = mergeInsertSort(new_array);
		std::vector<int> sorted = insert_sort(merge_array);
		// print_pair_vector(array);
		// std::cout << std::endl;
		merge_array = sort_large(sorted, array);
		return (merge_array);
	}
}

std::vector<int> PmergeMe::insert_sort(std::vector<t_pair> new_array) {
	std::vector<int> sorted;
	std::vector<int> small_array;
	// std::cout << "-----new_array------" << std::endl;
	// print_pair_vector(new_array);
	// std::cout << "--------------------" << std::endl;
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
			// std::cout << "size : " << small_array.size() << std::endl;
			int line = jacob_stahal_seq[i] - 1;
			if (small_array.size() == 0)
				break;
			if (static_cast<int>(small_array.size()) < jacob_stahal_seq[i])
				line = small_array.size() - 1;
			// std::cout << "line : " << line << std::endl;
			for (int j = line; j >= 0; j -= 1) {
				for (int k = 0; k < static_cast<int>(sorted.size());k++) {
					if (small_array[j] <= sorted[k]) {
						sorted.insert(sorted.begin() + k, small_array[j]);
						break ;
					}
					else if (k == static_cast<int>(sorted.size() - 1)) {
						sorted.push_back(small_array[line]);//ここで1が入ってしまう
						break ;
					}
					else if (sorted[k] <= small_array[j] && small_array[j] <= sorted[k + 1]) {
						sorted.insert(sorted.begin() + k + 1, small_array[j]);
						// std::cout << std::endl;
						break ;
					}
				}
			}
			small_array.erase(small_array.begin(), small_array.begin() + line + 1);
		}
		return (sorted);
	}
}

std::vector<t_pair> PmergeMe::sort_large(std::vector<int>base, std::vector<t_pair>pair_array) {
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
7 6 5 4 3 2 1





large 7
small 

large 7 -1
small 5 3

large 7 5 3 -1
small 6 4 2 1
*/

