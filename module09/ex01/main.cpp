/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:48 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 19:54:11 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parseNbr( std::stringstream & ss, std::stack<int> & stack)
{
	int nbr;

	ss >> nbr;
	if (ss.fail()) {
		std::cerr << "Error" << std::endl;
		return 0;
	}
	stack.push(nbr);
	return 1;
}

int parseOp( std::stringstream & ss, std::stack<int> & stack)
{
	char op;

	ss >> op;
	if (ss.fail()) {
		std::cerr << "Error" << std::endl;
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		std::cerr << "Format: ./RPN \" <int> <int> <operator> <int> <operator> <etc.>\"" << std::endl;
		return 1;
	}

	// check valid input

	std::stack<int> stack;
	std::stringstream ss(argv[1]);
	int		nbr;
	char	op;

	if (!parseNbr(ss, stack))
		return 1;

	bool expectingNbr = true;
	while (!ss.eof()) {
		if (expectingNbr) {
			if (!parseNbr(ss, stack))
				return 1;
		} else {
			if (!parseOp(ss, stack))
				return 1;
		}
		expectingNbr != expectingNbr;
	}
	if (stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::cout << stack.top() << std::endl;
	return 0;
}