#include "../include/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
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
			std::string value = buffer.substr(delim + 1,  buffer.size() - delim);
		if (isValidDate(date) == false) {
			std::cout << "Error: bad input date => " << date << std::endl;
			continue ;
		}
		if (isValidValue(value) == false) {
			std::cout << "Error: bad input value => " << value << std::endl;
			continue ;
		}

			std::cout << "--> " << date << " " << value << std::endl;
			ref[date] = std::atof(value.c_str());
		}
	}
}

void	BitcoinExchange::processFile(const std::string &path) const {
	std::string buffer;
	std::ifstream file(path.c_str());
	if (file.is_open() == false)
		throw(std::runtime_error("Could not open the text data file!"));
	std::getline(file, buffer);
	if (buffer != "date | value" && buffer.empty() == false)
		std::cerr << "First line Invalid!\n";
	while (std::getline(file, buffer)) {
		if (buffer.empty() == true)
			continue ;
		size_t delim = buffer.find("|");
		if (delim == std::string::npos) {
			std::cout << "Error: bad input => " << buffer << std::endl;
			continue ;
		}
		std::string date = buffer.substr(0, delim);
		std::string value = buffer.substr(delim + 1,  buffer.size() - delim);
		if (isValidDate(date) == false) {
			std::cout << "Error: bad input date => " << date << std::endl;
			continue ;
		}
		if (isValidValue(value) == false) {
			std::cout << "Error: bad input value => " << value << std::endl;
			continue ;
		}

	}
}
