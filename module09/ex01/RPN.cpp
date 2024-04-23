/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:42 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 16:05:21 by mwallage         ###   ########.fr       */
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

void RPN::_parseOp(char &c)
{
	if (_stack.size() < 2)
		throw InvalidNumberOfOperandsException();

	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();
	if (c == '+')
		_stack.push(left + right);
	else if (c == '-')
		_stack.push(left - right);
	else if (c == '/')
	{
		if (right == 0)
			throw FloatingPointException();
		_stack.push(left / right);
	}
	else if (c == '*')
		_stack.push(left * right);
	else
		throw InvalidOperatorException();
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