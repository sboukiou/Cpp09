#include "../include/exceptions.hpp"

InvalidArgument::InvalidArgument(void): message("Invalid Argument!") {}

InvalidArgument::InvalidArgument(const std::string &param): message("Invalid Parameter: " + param) {}

const char *InvalidArgument::what() const throw() {
	return (message.c_str());
}


InvalidDate::InvalidDate(void): message("Invalid Date!") {}

InvalidDate::InvalidDate(const std::string &param): message("Invalid Date: " + param) {}

const char *InvalidDate::what() const throw() {
	return (message.c_str());
}


InvalidValue::InvalidValue(void): message("Invalid Value!") {}

InvalidValue::InvalidValue(const std::string &param): message("Invalid Value: " + param) {}

const char *InvalidValue::what() const throw() {
	return (message.c_str());
}



FileNotOpened::FileNotOpened(void): message("Could not open the file!") {}

FileNotOpened::FileNotOpened(const std::string &param): message("Could not open the file: " + param) {}

const char *FileNotOpened::what() const throw() {
	return (message.c_str());
}


IOError::IOError(void): message("IO Error!") {}

IOError::IOError(const std::string &param): message("IO Error: " + param) {}

const char *IOError::what() const throw() {
	return (message.c_str());
}
