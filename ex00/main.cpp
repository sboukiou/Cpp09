#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

typedef struct data {
	std::string date;
	long int	value;
} t_data;

static void testInput(const int &ac, char **av, std::ifstream &file) {
	if (ac != 2)
		throw(std::runtime_error("ERR: Number of args is invalid"));
	file.open(av[1]);
	if (file.is_open() == false) {
		throw(std::runtime_error("Failed to open the file\n"));
	}
}

t_data	parse_line(const std::string &line) {
	t_data	data;
	return (data);
}

int main(int ac, char **av) {
	std::ifstream 				file;
	std::vector<std::string>	content;
	std::string					line;
	try {
		testInput(ac, av, file);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		std::exit(0);
	}
	while (file.eof() == false) {
		std::getline(file, line);
		content.push_back(line);
	}
	return (0);
}
