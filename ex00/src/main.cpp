// #include "../include/BitcoinExchange.hpp"
#include "../include/exceptions.hpp"
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <fstream>

void	 check_args(int ac, char **av) {
	std::string DBName = "./assets/data.csv";
	std::ifstream input_file(av[1]);
	if (input_file.is_open() == false)
		throw(InvalidArgument("input file!"));
	else
		input_file.close();
	std::ifstream database_file(DBName.c_str());
	std::string line;
	if (ac != 2)
		throw(InvalidArgument("Number of arguments is invalid!"));
	if (database_file.is_open() == false)
		throw(FileNotOpened(DBName));
	database_file.close();
	input_file.close();
}

void extract_line_data(std::string &line, std::map<std::string, float> &pairs) {
	std::string key("");
	std::string value("");
	float		numKey;
	size_t idx = 0;
	size_t len = line.size();
	while (idx < len && line[idx] != ',') {
			value.push_back(line[idx]);
			idx += 1;
	}
	while (idx < len) {
		key.push_back(line[idx]);
		idx += 1;
	}
	numKey = std::atof(key.c_str());
	pairs.insert(std::pair<std::string, float>(value, numKey));
}

std::map<std::string, float> load_database(int ac, char **av) {
	std::map<std::string, float> pairs;
	std::string line;
	std::ifstream db_file(av[1]);

	(void)ac;

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

float parse_value(std::string &value) {
	double numVal;
	char	*endptr;

	numVal = std::strtod(value.c_str(), &endptr);
	if (numVal == 0)
		throw(InvalidValue(value));
	if (endptr != NULL && *endptr)
		throw(InvalidValue(value));
	return (numVal);
}

void parse_key_string(std::string keyStr) {
	double year;
	double month;
	double day;
	char	*peek;
	char	*temp;

	year = std::strtod(keyStr.c_str(), &peek);
	if (year == 0)
		throw(InvalidDate(keyStr));
	if (year < 1 || year > 2025)
		throw(InvalidDate(keyStr));
	temp = peek;
	if (temp && *temp)
		temp += 1;
	month = std::strtod(temp, &peek);
	if (month == 0)
		throw(InvalidDate(keyStr));
	if (month < 1 && month > 12)
		throw(InvalidDate(keyStr));
	temp = peek;
	if (temp && *temp)
		temp += 1;
	day = std::strtod(temp, &peek);
	if (day == 0)
		throw(InvalidDate(keyStr));
	if (day < 1)
		throw(InvalidDate(keyStr));
	if (day > 28 && month == 2)
		throw(InvalidDate(keyStr));
	if (day > 30)
		throw(InvalidDate(keyStr));
}

void	process_input_line(std::string &line, std::map<std::string, float> &db_data) {
	size_t delim_idx = line.find('|');
	size_t i = 0;
	std::string value("");
	std::string date("");
	float numValue;

	if (delim_idx == std::string::npos)
		throw(InvalidArgument("NO delimiter found, Line is invalid"));
	while (i < delim_idx) {
		date.push_back(line[i]);
		i += 1;
	}
	parse_key_string(date);
	(void)db_data;
	(void)numValue;
	i += 1;
	while (i < line.size()) {
		value.push_back(line[i]);
		i += 1;
	}
	numValue = parse_value(value);

}

void	process_input_file(int ac, char **av) {
	std::ifstream input_file(av[1]);
	std::string line;
	std::string date;
	std::string value;
	std::map<std::string, float> input_pairs;

	input_pairs = load_database(ac, av);

	if(input_file.is_open() == false)
		throw(InvalidArgument("input file!"));
	getline(input_file, line);
	while (getline(input_file, line)) {
		try {
			process_input_line(line, input_pairs);
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

	try {
		/* Loading the DB data references */
		std::cout << "-------------  Start of the program -------------\n";
		std::cout << "------------- After loading the DB -------------\n";

		/* Processing the input file line at a time */
		process_input_file(ac, av);
		std::cout << "------------- After processing the DB -------------\n";
	}
	catch (std::runtime_error &err) {
		std::cerr << "ERROR: " << err.what() << std::endl;
	}
	return (0);
}
