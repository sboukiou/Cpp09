#include "./RPN.hpp"


int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Numbers of Arguments is invalid!\n";
		return (0);
	}
	std::string input = av[1];
	evaluateExp(input);
	return (0);
}
