/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:59:04 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form form("tax", 3, 2);
	Bureaucrat K;

	std::cout << form << std::endl;
	std::cout << K << std::endl;

	try
	{
		K.signForm(form);
		form.beSigned(K);
		K.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << form << std::endl;

	try
	{
		std::string name("Josef K.");
		Bureaucrat newK(name, 1);
		std::cout << newK << std::endl;
		newK.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}