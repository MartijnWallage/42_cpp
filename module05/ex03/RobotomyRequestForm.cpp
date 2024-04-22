/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:35:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 14:00:21 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("none")
{
	std::cout << "Default RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm with target " << _target
			  << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: _target(other._target)
{
	std::cout << "RobotomyRequestForm with target " << _target
			  << " copy constructed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &)
{
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm with target " << _target
			  << " destroyed" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void RobotomyRequestForm::beExecuted(Bureaucrat const &) const
{
	std::cout << "(Drilling noises.)" << std::endl;

	std::srand(time(0));
	int isRobotomized = std::rand() % 2;
	std::cout << "isRobotomized is " << isRobotomized << std::endl;
	if (isRobotomized)
	{
		std::cout << this->_target << " has been robotomized" << std::endl;
	}
	else
	{
		std::cout << "Robotomy has failed" << std::endl;
	}
}
