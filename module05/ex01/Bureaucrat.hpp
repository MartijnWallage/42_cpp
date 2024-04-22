/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:23 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:58:49 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	void checkGrade(void) const;

public:
	Bureaucrat(void);
	Bureaucrat(std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat(void);

	std::string getName(void) const;
	int getGrade(void) const;
	void incGrade(void);
	void decGrade(void);
	void signForm(Form &);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);