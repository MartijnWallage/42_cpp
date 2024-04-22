/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:52:48 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 14:06:18 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		std::cerr << "Format: ./RPN \" <int> <int> <operator> <int> <operator> <etc.>\"" << std::endl;
		return 1;
	}

	// check valid input
	// parse input as stack
	// calculate result
	// output result
}