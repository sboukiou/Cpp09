// #include "../include/BitcoinExchange.hpp"
#include "../include/exceptions.hpp"
#include <iostream>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <fstream>

std::ifstream check_args(int ac, char **av) {
	std::string DBName = "./assets/data.csv";
	std::ifstream input_file(av[1]);
	if (input_file.is_open() == false)
		throw(InvalidArgument("input file!"));
	else
		input_file.close();
	std::ifstream database_file(DBName);
	std::string line;
	if (ac != 2)
		throw(InvalidArgument("Number of arguments is invalid!"));
	if (database_file.is_open() == false)
		throw(FileNotOpened(DBName));

	return (database_file);

}

void extract_line_data(std::string &line, std::map<std::string, float> &pairs) {
	std::string key("");
	std::string value("");
	float		numKey;
	size_t idx = 0;
	size_t len = line.size();
	while (idx < len && line[idx] != ',')
			value.push_back(line[idx]);
	while (idx < len) {
		key.push_back(line[idx]);
		idx += 1;
	}
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
	db_file.close();
	return (pairs);
}

void	process_input_line(std::string &line, std::map<std::string, float> &db_data) {
	int delim_idx = line.find('|');
	int i = 0;
	std::string value("");
	std::string key("");

	if (delim_idx == std::string::npos)
		throw(InvalidArgument("NO delimiter found, Line is invalid"));
	while (i < delim_idx) {
		value.push_back(line[i]);
		i += 1;
	}
	// TODO: Parse value and check if any errors found
	// parse_value(value);
	i += 1;
	while (i < line.size()) {
		key.push_back(line[i]);
		i += 1;
	}
	// TODO: Parse key string and check if any errors found
	// parse_key_string(value);

}

void	process_input_file(int ac, char **av) {
	std::ifstream input_file(av[1]);
	std::string line;
	std::string date;
	std::string value;

	if(input_file.is_open() == false)
		throw(InvalidArgument("input file!"));
	getline(input_file, line);
	while (getline(input_file, line)) {
		try {
		//TODO: process_input_line(line);
		}
		catch (std::exception &err) {
			std::cout << "ERROR: " << err.what() << std::endl;
		}
	}

	if (input_file.bad()) {
		throw(IOError("Bad input"));
	} else if (!input_file.eof()) {
		throw(IOError("Nothing to read"));
	}
	input_file.close();

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
