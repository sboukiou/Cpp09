#include "./BitcoinExchange.hpp"
#include <iostream>

Btc::Btc(void): fileName("data.csv") {
	std::string buffer;

	file.open(fileName.c_str());
	if (file.is_open() == false)
		throw(std::runtime_error("Could not open the file!"));

	// Taking of the header

	std::getline(file, buffer);
	while (file.eof() == false) {
		std::getline(file, buffer);
		std::string::size_type pos = buffer.find(',');
		if (pos == std::string::npos && buffer.empty() == false) {
			std::cerr << "[line erro]: invalid format (no pipe was found)" << std::endl;
			std::cout << "--> "<< buffer << std::endl;
		}
		else {
			std::string left = buffer.substr(0, pos);
			std::string right = buffer.substr(pos + 1);
			ref.insert(std::make_pair(left, std::atoi(right.c_str())));
		}
	}
	std::map<std::string, double>::iterator it;
}


Btc::Btc(const std::string &fileName): fileName(fileName) {
	std::string buffer;

	file.open(fileName.c_str());
	if (file.is_open() == false)
		throw(std::runtime_error("Could not open the file!"));

	// Taking of the header

	std::getline(file, buffer);
	while (file.eof() == false) {
		std::getline(file, buffer);
		std::string::size_type pos = buffer.find(',');
		if (pos == std::string::npos) {
			std::cerr << "[line erro]: invalid format (no pipe was found)" << std::endl;
			std::cout << "--> "<< buffer << std::endl;
		}
		else {
			std::string left = buffer.substr(0, pos);
			std::string right = buffer.substr(pos + 1);
			ref.insert(std::make_pair(left, std::atoi(right.c_str())));
		}
	}
	std::map<std::string, double>::iterator it;
}


Btc::Btc(const Btc &other): fileName(other.fileName) {
	std::string buffer;

	file.open(fileName.c_str());
	if (file.is_open() == false)
		throw(std::runtime_error("Could not open the file!"));

	// Taking of the header

	std::getline(file, buffer);
	while (file.eof() == false) {
		std::getline(file, buffer);
		std::string::size_type pos = buffer.find(',');
		if (pos == std::string::npos) {
			std::cerr << "[line erro]: invalid format (no pipe was found)" << std::endl;
			std::cout << "--> "<< buffer << std::endl;
		}
		else {
			std::string left = buffer.substr(0, pos);
			std::string right = buffer.substr(pos + 1);
			ref.insert(std::make_pair(left, std::atoi(right.c_str())));
		}
	}
	std::map<std::string, double>::iterator it;
}

Btc::~Btc(void) {
	std::cout << "Cleanup: closing the file\n";
	file.close();
}


Btc&	Btc::operator=(const Btc &other){

	if (this == &other)
		return (*this);
	fileName = other.fileName;
	std::string buffer;

	file.open(fileName.c_str());
	if (file.is_open() == false)
		throw(std::runtime_error("Could not open the file!"));

	// Taking of the header

	std::getline(file, buffer);
	while (file.eof() == false) {
		std::getline(file, buffer);
		std::string::size_type pos = buffer.find(',');
		if (pos == std::string::npos) {
			std::cerr << "[line erro]: invalid format (no pipe was found)" << std::endl;
			std::cout << "--> "<< buffer << std::endl;
		}
		else {
			std::string left = buffer.substr(0, pos);
			std::string right = buffer.substr(pos + 1);
			ref.insert(std::make_pair(left, std::atoi(right.c_str())));
		}
	}
	std::map<std::string, double>::iterator it;
	return (*this);
}
