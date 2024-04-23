/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:42 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 16:23:32 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input)
{
	for (size_t i = 0; i < _input.size(); i++)
	{
		if ((i % 2) ^ (_input[i] == ' '))
			throw InvalidSpacingException();
	}
}

RPN::RPN(RPN const &other) : _input(other._input), _stack(other._stack)
{
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
		_input = other._input;
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

inline int sum(int a, int b) { return a + b; }

inline int subtract(int a, int b) { return a - b; }

inline int multiply(int a, int b) { return a * b; }

inline int divide(int a, int b) { return a / b; }

funcPtr RPN::_getOp(char &c)
{
	switch (c)
	{
	case '+':
		return (&sum);
	case '-':
		return (&subtract);
	case '*':
		return (&multiply);
	case '/':
		return (&divide);
	default:
		throw InvalidOperatorException();
	}
	return NULL;
}

void RPN::_parseOp(char &c)
{
	if (_stack.size() < 2)
		throw InvalidNumberOfOperandsException();

	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();
	if (right == 0 && c == '/')
		throw FloatingPointException();
	_stack.push(_getOp(c)(left, right));
}

int RPN::computeResult()
{
	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input[i] == ' ')
			continue;
		else if (std::isdigit(_input[i]))
			_stack.push(_input[i] - '0');
		else
			_parseOp(_input[i]);
	}

	if (_stack.size() != 1)
		throw InvalidFinalStackException();

	return (_stack.top());
}

const char *RPN::InvalidOperatorException::what() const throw()
{
	return "Error: invalid operator";
}

const char *RPN::InvalidSpacingException::what() const throw()
{
	return "Error: invalid spacing";
}

const char *RPN::InvalidNumberOfOperandsException::what() const throw()
{
	return "Error: invalid numbers of operands";
}

const char *RPN::InvalidFinalStackException::what() const throw()
{
	return "Error: failed to end with one solution";
}

const char *RPN::FloatingPointException::what() const throw()
{
	return "Error: cannot divide by zero";
}