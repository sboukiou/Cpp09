// #include "../include/BitcoinExchange.hpp"
#include "../include/exceptions.hpp"
#include <iostream>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <fstream>

std::ifstream check_args(int ac, char **av) {
	std::string DBName = "./assets/data.csv";
	std::string line;
	if (ac != 2)
		throw(InvalidArgument("Number of arguments is invalid!"));
	std::ifstream database_file(DBName);
	if (database_file.is_open() == false)
		throw(FileNotOpened(DBName));

	return (database_file);

}

void	process_input_file(int ac, char **av) {
	//TODO: Read one line at a time.
	//TODO: Process each line whether valid or not & pass to the next one.
}


void extract_line_data(std::string &line, std::map<std::string, float> &pairs) {
	std::string key("");
	std::string value("");
	float		numKey;
	size_t idx = 0;
	size_t len = line.size();
	while (idx < len && line[idx] != ',')
			value.push_back(line[idx]);
	while (idx < len)
			key.push_back(line[idx]);
	numKey = std::stof(key);
	pairs.insert(std::pair<std::string, float>(value, numKey));
}

std::map<std::string, float> load_database(int ac, char **av) {
	std::map<std::string, float> pairs;
	std::string line;
	std::ifstream db_file = check_args(ac, av);

	getline(db_file, line);
	while (getline(db_file, line))
		extract_line_data(line, pairs);

	if (db_file.bad()) {
		throw(IOError("Bad input"));
	} else if (!db_file.eof()) {
		throw(IOError("Nothing to read"));
	}
	return (pairs);
}

int main(int ac, char **av) {
	std::map<std::string, float> input_pairs;

	try {
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
