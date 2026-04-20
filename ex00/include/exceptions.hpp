#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <string>

class InvalidArgument: public std::exception {
	private:
		std::string message;
	public:
		InvalidArgument(void);
		InvalidArgument(const std::string &message);
		const char *what() const throw();
};


class InvalidDate: public std::exception {
	private:
		std::string message;
	public:
		InvalidDate(void);
		InvalidDate(const std::string &message);
		const char *what() const throw();
};


class InvalidValue: public std::exception {
	private:
		std::string message;
	public:
		InvalidValue(void);
		InvalidValue(const std::string &message);
		const char *what() const throw();
};

class FileNotOpened: public std::exception {
	private:
		std::string message;
	public:
		FileNotOpened(void);
		FileNotOpened(const std::string &message);
		const char *what() const throw();
};


class IOError: public std::exception {
	private:
		std::string message;
	public:
		IOError(void);
		IOError(const std::string &message);
		const char *what() const throw();
};

#endif /* EXCEPTIONS_HPP */
