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
					std::cerr << "Error: bad input in CSV => " << std::endl;
					std::exit(1);
				}
				if (!check_day(date)) {
					std::cerr << "Error: bad input in CSV => " << date << std::endl;
					std::exit(1);
				}
				std::string price;
				std::stringstream ss(buf.substr(11, buf.length() - 11));
				ss >> price;
				if (ss.fail() || !ss.eof()) {
					std::cerr << "Error: too large a number in CSV."<< std::endl;
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
		if (buf != "date | value" && check_day(key)) {
			std::stringstream ss(buf.substr(13, buf.length() - 13));
			std::cout << "buf :" << buf.substr(13, buf.length() - 13) << std::endl;
			double value;
			ss >> value;
			// std::string other;
			// ss >> other;
			// std::cout <<"value : " << value << std::endl;
			// std::cout << "other : " << other << std::endl;
			if (ss.fail())
				std::cerr << "Error: too large a number." << std::endl;
			else if (!ss.eof())
			{
				std::cerr << "Yes1" << std::endl;
				std::string other;
				ss >> other;
				std::cerr << "other :" << other << std::endl;
				std::cerr << "count :" << other.length() << std::endl;
				std::cerr << "Error not digit." << std::endl;
			}
			else
			{
				std::stringstream ss_int(buf.substr(13, buf.length() - 13));
				int i;
				ss >> i;
				if (ss.fail())
					std::cerr << "Error: too large a number." << std::endl;
				else {
					std::map<std::string, std::string>::iterator it = table.find(key);
					if (it != table.end()) {
						std::stringstream x(it -> second);
						double cal;
						x >> cal;
						std::cout << key << " => " << value << " = " << value * cal << std::endl;
					}
					else {
						std::map<std::string, std::string>::iterator it = table.lower_bound(key);
						if (it == table.begin())
							std::cerr << key << " No infomation" << std::endl;
						else {
							it--;
							std::stringstream x(it -> second);
							double cal;
							x >> cal;
							std::cout <<  key << " => " << value << " = " << value * cal << std::endl;
						}
					}

				}

			}
		}
		else {
			std::cerr << "here" << std::endl;
			std::cerr << "Error: bad input => " << key << std::endl;
		}
	}
}