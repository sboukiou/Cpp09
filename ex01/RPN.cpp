#include "./RPN.hpp"

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
