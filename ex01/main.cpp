#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

typedef enum e_op {
	PLUS,
	MINUS,
	MUL,
	DIV,
	NIL
}	t_op;


t_op	is_operator(char op) {
	if (op == '+')
		return (PLUS);
	if (op == '/')
		return (DIV);
	if (op == '*')
		return (MUL);
	if (op == '-')
		return (MINUS);
	return (NIL);
}

void	evaluate_expression(int left, int right, t_op op, std::stack<int> &yard) {
	if (op == PLUS)
		yard.push(left + right);
	if (op == MINUS)
		yard.push(left - right);
	if (op == MUL)
		yard.push(left * right);
	if (op == DIV) {
		if (right == 0)
			throw(std::logic_error("Division by zero!"));
		yard.push(left / right);
	}
}


int main(int ac, char **av) {
	//TODO: Parse av
	std::stack<int> yard;
	int	left;
	int	right;
	std::string expr(av[1]);
	t_op	op;

	if (ac != 2) {
		std::cout << "ERROR: Invalid token !\n";
		return (1);
	}
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
				try {
					evaluate_expression(left, right, op, yard);
				}
				catch (std::logic_error &e) {
					std::cout << "ERROR: " << e.what() << std::endl;
					return (1);
				}
			}
			else if (isdigit(expr[idx])) {
				yard.push(expr[idx] - '0');
			}
			else {
				std::cout << "ERROR: Invalid token !\n";
				return (1);
			}
		}
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
