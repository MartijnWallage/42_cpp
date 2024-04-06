/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:35:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 18:06:22 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
: AForm("default", 145, 137)
{
	std::cout << "Default ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: AForm(target, 145, 137)
{
	std::cout << "ShrubberyCreationForm with target " << _target
		<< " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & other )
: _target(other._target)
{
	std::cout << "ShrubberyCreationForm with target " << _target
		<< " copy constructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const & )
{
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm with target " << _target
		<< " destroyed" << std::endl;
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return _target;
}

void ShrubberyCreationForm::beExecuted( Bureaucrat const &bureaucrat ) const
{
	std::cout << "Bureaucrat " << bureaucrat.getName()
		<< " executed ShrubberyCreationForm"
		<< this->AForm::getName() << std::endl;
}
