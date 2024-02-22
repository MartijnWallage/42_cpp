/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:43 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:44 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cerr << "I can't complain if you don't tell me what to complain about!" << std::endl;
		return 1;
	}

    Harl 		harl;
	std::string	type(argv[1]);

	harl.complain(type);

    return 0;
}
