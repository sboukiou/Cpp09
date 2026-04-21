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
				throw(std::runtime_error("ERROR: Invalid token !\n"));
		}
	}
}

int main(int ac, char **av) {
	std::stack<int> yard;
	std::string expr(av[1]);

	if (ac != 2) {
		std::cout << "ERROR: Invalid token !\n";
		return (1);
	}
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
	std::cout << "---    " << result << "    ---\n";

	return (0);
}
