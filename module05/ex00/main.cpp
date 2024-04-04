/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/04 17:08:33 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"

int main( void ) {
	try {
		std::string	name("Josef K.");
		Bureaucrat* j = new Bureaucrat(name, 0);
		delete j;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "***********************************" << std::endl << std::endl;

	try {
		std::string	name("Josef K.");
		Bureaucrat* j = new Bureaucrat(name, 151);
		delete j;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "***********************************" << std::endl << std::endl;

	try {
		Bureaucrat	K;
		K.decGrade();
		K.incGrade();
		K.decGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}