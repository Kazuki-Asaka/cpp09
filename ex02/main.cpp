#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 3) {
		std::cerr << "Error arg" << std::endl;
		return(1);
	} 
	else {
		PmergeMe sort;
		for (int i = 1; i < argc; i++)
			sort.add_str_num(argv[i]);
		sort.startMergeInsertSort();

	}
	return (0);
}