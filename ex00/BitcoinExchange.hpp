#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
class Btc {
	private:
		std::map<std::string, double> ref;
		std::string fileName;
		std::ifstream	file;
	public:
		Btc(void);
		Btc(const std::string &fileName);
		Btc(const Btc &other);
		~Btc(void);
		Btc&	operator=(const Btc &other);


};

#endif /* BITCOIN_EXCHANGE_HPP */
