/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:46:28 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:59:59 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Nameless intern hired" << std::endl;
}

Intern::Intern(Intern const &)
{
	std::cout << "Nameless intern copy constructed" << std::endl;
}

Intern &Intern::operator=(Intern const &)
{
	std::cout << "Nameless intern copy assigned" << std::endl;
	return *this;
}

Intern::~Intern(void)
{
	std::cout << "Nameless intern released" << std::endl;
}

AForm *makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string commands[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *(*creators[])(std::string target) = {&makeRobotomy, &makePresidential, &makeShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (commands[i] == form)
		{
			std::cout << "Form " << form << " found" << std::endl;
			return creators[i](target);
		}
	}
	throw InvalidFormRequestException();
	return (NULL);
}

const char *Intern::InvalidFormRequestException::what() const throw()
{
	return "Intern: invalid form request";
}
