#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

typedef struct data {
	std::string date;
	long int	value;
} t_data;

static void testInput(const int &ac, char **av, std::ifstream &file) {
	(void)av;
	(void)file;
	if (ac != 2)
		throw(std::runtime_error("ERR: Number of args is invalid"));
}

int main(int ac, char **av) {
	std::ifstream 				file;
	std::string					line;
	try {
		testInput(ac, av, file);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		std::exit(0);
	}
	// std:: cout << "** Loading the DB **\n";
	BitcoinExchange newRef;
	// std:: cout << "** Loading the data.txt file **\n";
	newRef.processFile(av[1]);
	newRef.execute();
	// std::cout << "Finished the work\n";
	return (0);
}
