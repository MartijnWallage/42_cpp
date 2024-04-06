/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:35:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/05 16:33:40 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
: AForm("default", 25, 5), _target("default target")
{
	std::cout << "Default Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
: AForm("default", 25, 5), _target(target)
{
	std::cout << "Presidential Pardon Form with target " << _target
		<< " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & other )
: _target(other._target)
{
	std::cout << "Presidential Pardon Form with target " << _target
		<< " copy constructed" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const & )
{
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "Presidential Pardon Form with target " << _target
		<< " destroyed" << std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return _target;
}

void PresidentialPardonForm::beExecuted( Bureaucrat const & ) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
