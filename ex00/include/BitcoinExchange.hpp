#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <iostream>
#include <map>
#include <stdexcept>
#include <fstream>
#include <string>
#include <cstdlib>
#include <climits>

class InvalidArgument: public std::exception {
	private:
		std::string message;
	public:
		InvalidArgument(void);
		~InvalidArgument(void) throw();
		InvalidArgument(const std::string &message);
		const char *what() const throw();
};


class InvalidDate: public std::exception {
	private:
		std::string message;
	public:
		InvalidDate(void);
		~InvalidDate(void) throw();
		InvalidDate(const std::string &message);
		const char *what() const throw();
};


class InvalidValue: public std::exception {
	private:
		std::string message;
	public:
		InvalidValue(void);
		~InvalidValue(void) throw();
		InvalidValue(const std::string &message);
		const char *what() const throw();
};

class FileNotOpened: public std::exception {
	private:
		std::string message;
	public:
		FileNotOpened(void);
		~FileNotOpened(void) throw();
		FileNotOpened(const std::string &message);
		const char *what() const throw();
};


class IOError: public std::exception {
	private:
		std::string message;
	public:
		IOError(void);
		~IOError(void) throw();
		IOError(const std::string &message);
		const char *what() const throw();
};



void	 check_args(int ac, char **av);
void extract_line_data(std::string &line, std::map<std::string, float> &pairs);
std::map<std::string, float> load_database(int ac, char **av);
float parse_value(std::string &value);
void validate_days(int year, int month, int day, std::string &keyStr);
void parse_key_string(std::string keyStr);
void	process_input_line(std::string &line, std::map<std::string, float> &db_data);


#endif /* EXCEPTIONS_HPP */
