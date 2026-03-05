#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

enum Type {
	DB,
	DATA
};

#include <map>
#include <string>
class BitcoinExchange {
	private:
		std::map<std::string, double> ref;
		std::map<std::string, double> data;
		std::string fileName;
		void	loadDataBase(void);
	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string &fileName);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange &other);
		void	processFile(const std::string &path);


};

 /* Util Functions */

bool	isValidValue(std::string &value);
bool	isValidDate(std::string &param);
void	processLine(std::map<std::string, double> &ref, std::string buffer, Type type);
void trim(std::string& s);
void split(std::string &left, std::string &right, std::string &src, char delim);

#endif /* BITCOIN_EXCHANGE_HPP */
