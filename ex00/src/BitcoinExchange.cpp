#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
BitcoinExchange::BitcoinExchange(void): fileName("./assets/data.csv") {
	loadDataBase();
}

BitcoinExchange::BitcoinExchange(const std::string &param): fileName(param) {
	loadDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): ref(other.ref), fileName(other.fileName) {
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << "Class object leaving ...\n";
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other) {
	fileName = other.fileName;
	ref = other.ref;
	return (*this);
}

void	BitcoinExchange::loadDataBase(void) {
	std::ifstream file(fileName.c_str());
	std::string buffer("");
	if (file.is_open() == false)
		throw(std::runtime_error("could not open file."));
	while (std::getline(file, buffer)) {
		if (buffer == "date,exchange_rate")
			continue ;
		try {
			processLine(ref, buffer, DB);
		}
		catch (std::exception &e) {
			std::cout << "Error:" << e.what() << std::endl;
		}
	}
	file.close();
}

void	BitcoinExchange::processFile(const std::string &path) {
	std::ifstream file(path.c_str());
	std::string buffer("");
	if (file.is_open() == false)
		throw(std::runtime_error("could not open file."));
	while (std::getline(file, buffer)) {
		if (buffer == "date | value")
			continue ;
		try {
			processLine(ref, buffer, DATA);
		}
		catch (std::exception &e) {
			std::cout << "Error:" << e.what() << std::endl;
		}
	}
}
