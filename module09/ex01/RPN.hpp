/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:30 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 15:58:01 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
private:
	std::string _input;
	std::stack<int> _stack;
	void _parseOp(char &c);

public:
	RPN(std::string input);
	RPN(RPN const &);
	RPN &operator=(RPN const &);
	~RPN();

	int computeResult(void);
	class InvalidOperatorException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidSpacingException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidNumberOfOperandsException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidFinalStackException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class FloatingPointException : public std::exception
	{
		virtual const char *what() const throw();
	};
};
