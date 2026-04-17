<<<<<<< HEAD
#include <iostream>
#include "./RPN.hpp"

int main(void) {
	std::cout << "Hello, World!\n";
	testRPN();
=======
#include "./RPN.hpp"


int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Numbers of Arguments is invalid!\n";
		return (0);
	}
	std::string input = av[1];
	evaluateExp(input);
>>>>>>> ee22b475ac2e731466f0f0922b0680a55f14bbac
	return (0);
}
