/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:46:28 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 20:20:25 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << "Nameless intern hired" << std::endl;

	std::string	requests[] =
		{"robotomy request", "presidential pardon", "shrubbery creation"};
	void ( AForm::*constructors[3] )( std::string formTarget );

}

Intern::Intern( Intern const & ) {
	std::cout << "Nameless intern copy constructed" << std::endl;
}

Intern& Intern::operator=( Intern const & ) {
	std::cout << "Nameless intern copy assigned" << std::endl;
}

Intern::~Intern( void ) {
	std::cout << "Nameless intern released" << std::endl;
}

AForm* Intern::makeForm(std::string form, std::string target) {

	try {
		ret = AForm::makeForm(form, target);
		std::cout << form << "made" << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return ret;
}
