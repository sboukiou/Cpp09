<<<<<<< HEAD
# include "./RPN.hpp"
#include <iostream>


void testRPN(void) {
	std::cout << "Testing the RPN module\n";
}
=======
#include "./RPN.hpp"

void	evaluateExp(std::string &var) {
	std::stack<int> hold;
	for (size_t i = 0; i < var.length(); i += 1) {
		if (var[i] == '+' || var[i] == '-' || var[i] == '*' || var[i] == '/') {
			if (hold.size() < 2)
				throw(std::runtime_error("Invalid format!"));
			int right = hold.top();
			hold.pop();
			int left = hold.top();
			if (var[i] == '+')
				hold.push(right + left);
			else if (var[i] == '-')
				hold.push(left - right);
			else if (var[i] == '*')
				hold.push(left * right);
			else if (var[i] == '/')
				hold.push(left / right);
		}
		else if (isdigit(var[i]))
			hold.push(var[i] - '0');
	}
	std::cout << hold.top() << std::endl;
}

>>>>>>> ee22b475ac2e731466f0f0922b0680a55f14bbac
