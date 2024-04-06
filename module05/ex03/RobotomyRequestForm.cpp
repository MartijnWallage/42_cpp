/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:35:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 18:11:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
: AForm("default", 72, 45)
{
	std::cout << "Default RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
: AForm(target, 72, 45)
{
	std::cout << "RobotomyRequestForm with target " << _target
		<< " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & other )
: _target(other._target)
{
	std::cout << "RobotomyRequestForm with target " << _target
		<< " copy constructed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const & )
{
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm with target " << _target
		<< " destroyed" << std::endl;
}

std::string RobotomyRequestForm::getTarget( void ) const {
	return _target;
}

void RobotomyRequestForm::beExecuted( Bureaucrat const &bureaucrat ) const
{
	std::cout << "Bureaucrat " << bureaucrat.getName()
		<< " executed RobotomyRequestForm"
		<< this->AForm::getName() << std::endl;
}
