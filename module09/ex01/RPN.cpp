/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:42 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/23 14:58:47 by mwallage         ###   ########.fr       */
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
