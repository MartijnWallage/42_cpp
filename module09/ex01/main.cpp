/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:48 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 14:58:43 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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