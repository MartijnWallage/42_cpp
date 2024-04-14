/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:46:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/14 17:19:49 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalarConverter.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2 ) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	std::string const	input(argv[1]);
	try {
		scalarConverter::convert(input);
	}
	catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
	}

    return 0;
}
