/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/04 17:48:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"

int main( void ) {
	std::string	name("Josef K.");

	Bureaucrat	a;
	Bureaucrat	b(name, 10);
	std::cout << b << std::endl;
	b.decGrade();
	b.incGrade();
	b = a;
	std::cout << b << std::endl;

	std::cout << "***********************************" << std::endl;
	try {
		Bureaucrat* j = new Bureaucrat(name, 0);
		delete j;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "***********************************" << std::endl;

	try {
		Bureaucrat* j = new Bureaucrat(name, 151);
		delete j;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "***********************************" << std::endl;
	
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