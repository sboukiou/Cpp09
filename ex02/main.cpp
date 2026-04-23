#include "./main.hpp"


int main(int ac, char **av) {
	std::vector<int> numbers;


	try {
		numbers = parse_input(ac, av);
	}
	catch (std::runtime_error &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	sort_vector(numbers);
	return (0);
}
