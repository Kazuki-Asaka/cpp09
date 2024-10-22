#include "BitcoinExchange.hpp"

bool check_valid_day(int year, int month, int date) {
	if (year < 0 || month < 1 || 12 < month)
		return (false);
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (date < 1 || 31 < date)
			return (false);	
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (date < 1 || 30 < date)
			return (false);
	}
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		if (month == 2) {
			if (date < 1 || 29 < date)
				return (false);
		}
	}
	else {
		if (month == 2)
			if (date < 1 || 28 < date)
				return (false);
	}
	return (true);
}

bool check_day(std::string day) {
	int year;
	int month;
	int date;

	if (day.length() !=  10 || day[4] != '-' || day[7] != '-') 
		return (false);
	std::string str = day.substr(0,4);
	std::stringstream ss(str);
	ss >> year;
	if (ss.fail() || !ss.eof())
		return(false);
	ss.clear();
	ss.str("");
	ss.str(day.substr(5,2));
	ss >> month;
	if (ss.fail() || !ss.eof())
		return(false);
	ss.clear();
	ss.str("");
	ss.str(day.substr(8,2));
	ss >> date;
	if (ss.fail() || !ss.eof())
		return(false);
	// std::cout << year << std::endl;
	// std::cout << month << std::endl;
	// std::cout << date << std::endl;
	if (!check_valid_day(year, month, date))
		return(false);
	return (true);
}

std::map<std::string, std::string>  store_map() {
	std::map<std::string, std::string> table;
	std::ifstream ifs("data.csv");
	if (!ifs) {
		std::cerr << "Error file not found" << std::endl;
		std::exit(1);
	}
	else {
		std::string buf;
		while (std::getline(ifs, buf)) {
			if (buf != "date,exchange_rate") {
				std::string date = buf.substr(0,10);
				// std::cout << date << std::endl;
				if (buf[10] != ',') {
					std::cerr << "Error CSV date is incorrect "<< std::endl;
					std::exit(1);
				}
				std::string price;
				std::stringstream ss(buf.substr(11, buf.length() - 11));
				ss >> price;
				if (ss.fail()) {
					std::cerr << "Error: CSV data is incorrect" << std::endl;
					std::exit(1);
				}
				table[date] = price;
			}
		}
		return (table);
	}
}//csv側で読み込んだもののエラー処理をする必要あり

void output_btc(char *inputfile, std::map<std::string, std::string>table) {
	std::ifstream ifs(inputfile);
	if(!ifs) {
		std::cerr << "Error file not found" << std::endl;
		std::exit(1);
	}
	std::string buf;
	while (std::getline(ifs, buf)) {
		std::string key = buf.substr(0, 10);
		if (check_day(key)) {
			
		}
		else {
			std::cerr << "Error: bad input" << std::endl;
		}
	}
}