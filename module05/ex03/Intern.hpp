/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:41:29 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/07 17:26:23 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern( void );
		Intern( Intern const & );
		Intern& operator=( Intern const & );
		~Intern( void );

		AForm* makeForm(std::string form, std::string target);

		class InvalidFormRequestException: public std::exception {
			virtual const char* what() const throw();
		};
};

AForm*	makeShrubbery( std::string target );
AForm*	makePresidential( std::string target );
AForm*	makeRobotomy( std::string target );