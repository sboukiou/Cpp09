#include "./main.hpp"


int main(int ac, char **av) {

	std::cout << "----------------- Sorting with vector -----------------\n";
	try {
		sort_with_vector(ac, av);
	}
	catch (std::runtime_error &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	std::cout << "----------------- Sorting with Deque -----------------\n";
	try {
		sort_with_deque(ac, av);
	}
	catch (std::runtime_error &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
