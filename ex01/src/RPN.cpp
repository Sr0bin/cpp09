/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:50:34 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 14:50:34 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <climits>
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

RPN::~RPN()
{
}

const char	*RPN::InvalidExpression::what() const throw()
{
	return ("Error");
}

int	RPN::evaluate(const std::string &expression) const
{
	std::stack<int>		operands;
	std::istringstream	stream(expression);
	std::string			token;

	while (stream >> token)
	{
		if (token.size() != 1)
			throw InvalidExpression();
		char	c = token[0];
		if (std::isdigit(static_cast<unsigned char>(c)))
			operands.push(c - '0');
		else if (isOperator(c))
			applyOperator(operands, c);
		else
			throw InvalidExpression();
	}
	if (operands.size() != 1)
		throw InvalidExpression();
	return (operands.top());
}

void	RPN::applyOperator(std::stack<int> &operands, char op) const
{
	if (operands.size() < 2)
		throw InvalidExpression();
	int	rhs = operands.top();
	operands.pop();
	int	lhs = operands.top();
	operands.pop();
	operands.push(compute(op, lhs, rhs));
}

int	RPN::compute(char op, int lhs, int rhs) const
{
	if (op == '+')
	{
		if ((rhs > 0 && lhs > INT_MAX - rhs) || (rhs < 0 && lhs < INT_MIN - rhs))
			throw InvalidExpression();
		return (lhs + rhs);
	}
	if (op == '-')
	{
		if ((rhs < 0 && lhs > INT_MAX + rhs) || (rhs > 0 && lhs < INT_MIN + rhs))
			throw InvalidExpression();
		return (lhs - rhs);
	}
	if (op == '*')
	{
		if (multiplicationOverflows(lhs, rhs))
			throw InvalidExpression();
		return (lhs * rhs);
	}
	if (rhs == 0 || (lhs == INT_MIN && rhs == -1))
		throw InvalidExpression();
	return (lhs / rhs);
}

bool	RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	RPN::multiplicationOverflows(int lhs, int rhs)
{
	if (lhs == 0 || rhs == 0)
		return (false);
	if (lhs > 0)
	{
		if (rhs > 0)
			return (lhs > INT_MAX / rhs);
		return (rhs < INT_MIN / lhs);
	}
	if (rhs > 0)
		return (lhs < INT_MIN / rhs);
	return (lhs < INT_MAX / rhs);
}
