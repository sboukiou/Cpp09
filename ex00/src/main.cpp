#include "../include/BitcoinExchange.hpp"

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
		/* Processing the input file line at a time */
		process_input_file(ac, av);
	}
	catch (std::runtime_error &err) {
		std::cerr << "ERROR: " << err.what() << std::endl;
	}
	return (0);
}
