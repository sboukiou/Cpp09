#include <iostream>
#include <fstream>
#include <vector>

static void testInput(const int &ac, char **av, std::ifstream &file) {
	if (ac != 2)
		throw(std::runtime_error("ERR: Number of args is invalid"));
	file.open(av[1]);
	if (file.is_open() == false) {
		throw(std::runtime_error("Failed to open the file\n"));
	}
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
	}
	while (file.eof() == false) {
		std::getline(file, line);
		content.push_back(line);
	}
	for (size_t i = 0; i < content.size(); i += 1)
		std::cout << content[i] << std::endl;
	file.close();
	return (0);
}
