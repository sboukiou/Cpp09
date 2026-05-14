#include "./main.hpp"

//TODO: Check for duplicates and eliminate them, duplicates --> Invalid input
//TODO: Format the ouput to look just the same as stated in the subject

int main(int ac, char **av) {

	try {
		sort_with_vector(ac, av);
	}
	catch (std::runtime_error &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	try {
		sort_with_deque(ac, av);
	}
	catch (std::runtime_error &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
