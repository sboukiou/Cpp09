#include "./main.hpp"


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
