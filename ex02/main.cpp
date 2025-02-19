#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 3 || 5001 < argc) {
		std::cerr << "Error arg" << std::endl;
		return(1);
	} 
	else {
		PmergeMe sort;
		for (int i = 1; i < argc; i++)
			sort.add_str_num(argv[i]);
		sort.startMergeInsertSort_vec();
		sort.startMergeInsertSort_deq();
		// sort.check_vec_and_deq();
	}
	return (0);
}

/*
test_case
./PmergeMe 21 1 13 2 17 3 12 4 20 5 15 6 19 7 14 8 18 9 16 10 11
./PmergeMe 5 5 4 3 2 1
./PmergeMe "5 5" 4 3 2 1
./PmergeMe 1
./PmergeMe "-1" "2"
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
./PmergeMe `shuf -i 1-100000 -n 5000 | tr "\n" " "`
./PmergeMe `shuf -i 1-100000 -n 5001 | tr "\n" " "`

./PmergeMe " " 1
./PmergeMe "3" 1
./PmergeMe "3" 1 ""
./PmergeMe "3" 1 a 
*/