#include "../include/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

void check_args(int ac, char **av) {
}

void	process_input_file(int ac, char **av) {

}

int main(int ac, char **av) {
	std::map<std::string, float> input_pairs;

	try {
		/* Checking if the input file exists and has text in it */
		check_args(ac, av);

		/* Loading the DB data references */
		input_pairs = load_database(ac, av);

		/* Processing the input file line at a time */
		process_input_file(ac, av);
	}
	catch (std::runtime_error &err) {
		std::cerr << "ERROR: " << err.what() << std::endl;
	}
	return (0);
}
