#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <map>


std::map<std::string, std::string>  store_map();
void output_btc(char* inputfile, std::map<std::string, std::string>table);
bool check_day(std::string day);
bool check_valid_day(int year, int month, int date);

#endif