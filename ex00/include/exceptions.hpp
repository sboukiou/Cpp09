#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <string>

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

#endif /* EXCEPTIONS_HPP */
