/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:48 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 14:56:44 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int parseOp(char &c, std::stack<int> &stack)
{
	if (stack.size() != 2)
	{
		std::cerr << "Error: wrong number of operands for operator '" << c << "'." << std::endl;
		return 0;
	}
	int nbrs[2];

	nbrs[1] = stack.top();
	stack.pop();
	nbrs[0] = stack.top();
	stack.pop();
	if (c == '+')
		stack.push(nbrs[0] + nbrs[1]);
	else if (c == '-')
		stack.push(nbrs[0] - nbrs[1]);
	else if (c == '/')
		stack.push(nbrs[0] / nbrs[1]);
	else if (c == '*')
		stack.push(nbrs[0] * nbrs[1]);
	else
	{
		std::cerr << "Error: invalid operator" << std::endl;
		return 0;
	}

	return 1;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Format: ./RPN \" <int> <int> <operator> <int> <operator> <etc.>\"" << std::endl;
		return 1;
	}

	std::stack<int> stack;
	std::string input(argv[1]);

	bool expectingSpace = false;
	for (size_t i = 0; i < input.length(); i++)
	{
		if ((expectingSpace && input[i] != ' ') || (!expectingSpace && input[i] == ' '))
		{
			std::cerr << "Error: invalid spacing" << std::endl;
			return 1;
		}
		expectingSpace = !expectingSpace;
		if (input[i] == ' ')
			continue;
		else if (std::isdigit(input[i]))
			stack.push(input[i] - '0');
		else if (!parseOp(input[i], stack))
			return 1;
	}

	if (stack.size() != 1)
	{
		std::cerr << "Error: failed to end with one solution" << std::endl;
		return 1;
	}
	std::cout << stack.top() << std::endl;

	return 0;
}