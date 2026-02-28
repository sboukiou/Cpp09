#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
class BitcoinExchange {
	private:
		std::map<std::string, double> ref;
		std::string fileName;
		void	loadDataBase(void) const;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string &fileName);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange &other);
		void	processFile(const std::string &path) const;


};

#endif /* BITCOIN_EXCHANGE_HPP */
