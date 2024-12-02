#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc == 1)
		std::cerr << "Error: could not open file." << std::endl;
	else if (argc == 2) {
		std::map<std::string, std::string> table = store_map();
		// std::cout << argv[1]  << std::endl;
		output_btc(argv[1], table);
		// std::cout << "map: " << table["2022-03-25"] << std::endl;
	}
	else 
		std::cerr << "Error: argc is more" << std::endl;

	// check_day("2012-3.1-11");
}
