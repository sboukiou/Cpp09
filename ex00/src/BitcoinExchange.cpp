#include "../include/BitcoinExchange.hpp"

InvalidArgument::InvalidArgument(void): message("Invalid Argument!") {}
InvalidArgument::~InvalidArgument(void) throw() {}

InvalidArgument::InvalidArgument(const std::string &param): message("Invalid Parameter: " + param) {}

const char *InvalidArgument::what() const throw() {
	return (message.c_str());
}


InvalidDate::InvalidDate(void): message("Invalid Date!") {}
InvalidDate::~InvalidDate(void) throw() {}

InvalidDate::InvalidDate(const std::string &param): message("Invalid Date: " + param) {}

const char *InvalidDate::what() const throw() {
	return (message.c_str());
}


InvalidValue::InvalidValue(void): message("Invalid Value!") {}
InvalidValue::~InvalidValue(void) throw() {}

InvalidValue::InvalidValue(const std::string &param): message("Invalid Value: " + param) {}

const char *InvalidValue::what() const throw() {
	return (message.c_str());
}



FileNotOpened::FileNotOpened(void): message("Could not open the file!") {}
FileNotOpened::~FileNotOpened(void) throw() {}

FileNotOpened::FileNotOpened(const std::string &param): message("Could not open the file: " + param) {}

const char *FileNotOpened::what() const throw() {
	return (message.c_str());
}


IOError::IOError(void): message("IO Error!") {}
IOError::~IOError(void) throw() {}

IOError::IOError(const std::string &param): message("IO Error: " + param) {}

const char *IOError::what() const throw() {
	return (message.c_str());
}
