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
	}
	return (0);
}