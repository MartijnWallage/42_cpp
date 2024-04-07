/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/07 17:16:51 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main( void ) {
	std::string	target("Marc Rich");
	std::string	name("Josef K.");
	Bureaucrat	K(name, 3);
	Intern		intern;
	AForm*		form;
	
	try {
		form = intern.makeForm("robotomy request", target);
		K.signForm(*form);
		K.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		form = intern.makeForm("presidential pardon", target);
		K.signForm(*form);
		K.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		form = intern.makeForm("shrubbery creation", target);
		K.signForm(*form);
		K.executeForm(*form);
		delete form;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		form = intern.makeForm("shrub creation", target);
		K.signForm(*form);
		K.executeForm(*form);
		delete form;	
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}