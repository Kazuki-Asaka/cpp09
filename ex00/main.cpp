#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc == 1)
		std::cerr << "Error: could not open file." << std::endl;
	else if (argc == 2) {
		std::map<std::string, std::string> table = store_map();
		output_btc(argv[1], table);
	}
	else 
		std::cerr << "Error: argc is more" << std::endl;
}
