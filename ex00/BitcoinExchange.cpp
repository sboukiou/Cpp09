#include "./BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
BitcoinExchange::BitcoinExchange(void): fileName("data.csv") {
	loadDataBase();
}

BitcoinExchange::BitcoinExchange(const std::string &param): fileName(param) {
	loadDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): fileName(other.fileName) {
	loadDataBase();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other) {
	fileName = other.fileName;
	ref = other.ref;
	loadDataBase();
	return (*this);
}

void	BitcoinExchange::loadDataBase(void) const {

	std::string buffer;

	std::ifstream file(fileName.c_str());
	if (file.is_open() == false)
		throw(std::runtime_error("Could not open the csv db file!"));
	std::getline(file, buffer);
	while (std::getline(file, buffer)) {
		size_t delim = buffer.find(",");
		if (delim == std::string::npos)
			std::cerr << "Invalid line, could not find the delimiter\n";
		else {
			std::string date = buffer.substr(0, delim);
			std::string value = buffer.substr(delim,  buffer.size() - delim);
			std::cout << "--> " << date << " " << value << std::endl;
		}
	}
}
