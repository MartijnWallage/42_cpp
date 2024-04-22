/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:59:24 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::string target("Marc Rich");
	std::string name("Josef K.");

	// PresidentialPardonForm:

	try
	{
		PresidentialPardonForm form(target);
		Bureaucrat K(name, 5);
		K.executeForm(form);
		K.signForm(form);
		K.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		PresidentialPardonForm form(target);
		Bureaucrat K(name, 25);
		K.signForm(form);
		K.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// ShrubberyCreationForm:

	try
	{
		ShrubberyCreationForm form(target);
		Bureaucrat K(name, 146);
		K.executeForm(form);
		K.signForm(form);
		K.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		ShrubberyCreationForm form(target);
		Bureaucrat K(name, 137);
		K.signForm(form);
		K.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	//	Robotomy Request Form

	try
	{
		RobotomyRequestForm form(target);
		Bureaucrat K(name, 72);
		K.executeForm(form);
		K.signForm(form);
		K.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		RobotomyRequestForm form(target);
		Bureaucrat K(name, 45);
		K.signForm(form);
		K.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}