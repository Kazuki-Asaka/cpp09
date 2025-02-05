#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 3) {
		std::cerr << "Error arg" << std::endl;
		return(1);
	} 
	else {
		PmergeMe sort;
		for (int i = 1; i < argc; i++) {
			if (sort.add_str_num(argv[i]) == -1)
				return (1);
		}
		sort.printVector();
	}
	return (0);
}