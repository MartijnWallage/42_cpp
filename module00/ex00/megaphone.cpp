/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:17:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:17:50 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	
		return 0;
	}

	for (int i = 1; i < argc; ++i) {
		std::string input = argv[i];

		for (size_t j = 0; j < input.length(); j++) {
			input[j] = std::toupper(input[j]);
		}
		std::cout << input;
	}
	std::cout << std::endl;

	return 0;
}