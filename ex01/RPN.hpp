#ifndef RPN_HPP
# define RPN_HPP

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


t_op	is_operator(char op);
void	evaluate_expression(int left, int right, t_op op, std::stack<int> &yard);

#endif /* RPN_HPP */
