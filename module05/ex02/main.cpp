/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 18:36:55 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
	std::string				target("Marc Rich");
	PresidentialPardonForm	form(target);
	std::string				name("Josef K.");
	Bureaucrat				K(name, 1);

	try {
		K.signForm( form );
		K.executeForm( form );
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		for (int i = 0; i < 30; i++)
			K.decGrade();
		K.executeForm( form );
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}