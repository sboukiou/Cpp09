#include "./RPN.hpp"

static	void process_stack(std::string &expr, std::stack<int> &yard) {
	int	left;
	int	right;
	t_op op;

	for (size_t idx = 0; idx < expr.size(); idx += 1) {
		if (expr[idx] != ' ') {
			op = is_operator(expr[idx]);
			if (op!= NIL) {
				if (yard.empty() == true)
					throw(std::runtime_error("Not enough tokens!"));
				right = yard.top();
				yard.pop();
				if (yard.empty() == true)
					throw(std::runtime_error("Not enough tokens!"));
				left = yard.top();
				yard.pop();
				evaluate_expression(left, right, op, yard);
			}
			else if (isdigit(expr[idx])) {
				yard.push(expr[idx] - '0');
			}
			else
				throw(std::runtime_error("Invalid token !\n"));
		}
	}
	if (yard.size() != 1)
		throw(std::runtime_error("Invalid Args provided!"));
}

int main(int ac, char **av) {
	std::stack<int> yard;
	std::string expr;

	if (ac != 2) {
		std::cout << "ERROR:  No arguments were provided !\n";
		return (1);
	}
	expr = std::string(av[1]);
	try {
	process_stack(expr, yard);
	}
	catch(std::runtime_error &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		return (1);
	}
	int result = yard.top();
	yard.pop();
	if (yard.empty() == false) {
		std::cout << "ERROR: Invalid token !\n";
		return (1);
	}
	std::cout << result << std::endl;

	return (0);
}
