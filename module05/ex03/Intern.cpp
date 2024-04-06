/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:46:28 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 19:54:10 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	std::cout << "Nameless intern hired" << std::endl;
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
	AForm	*ret;

	if (form == "PresidentialPardonForm")
		ret = new PresidentialPardonForm(target);
	else if (form == "ShrubberyCreationForm")
		ret = new ShrubberyCreationForm(target);
	else if (form == "RobotomyRequestForm")
		ret = new RobotomyRequestForm(target);
	else {
		std::cerr << "Unknown form" << std::endl;
		return NULL;
	}
	return ret;
}
