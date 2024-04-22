/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:35:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:58:54 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name("default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "Form " << _name << " created." << std::endl;
}

Form::Form(std::string name, int const signGrade, int const execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_signGrade > 150)
		throw Form::GradeTooLowException();
	if (this->_execGrade < 1)
		throw Form::GradeTooHighException();
	else if (this->_execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << _name << " created." << std::endl;
}

Form::Form(Form const &other)
	: _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Form " << _name << " copy constructed" << std::endl;
}

Form &Form::operator=(Form const &other)
{
	_isSigned = other._isSigned;
	std::cout << "Form " << _name << " copy asisSigned" << std::endl;
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

std::string Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

int Form::getSignGrade(void) const
{
	return _signGrade;
}

int Form::getExecGrade(void) const
{
	return _execGrade;
}

void Form::beSigned(Bureaucrat &k)
{
	if (k.getGrade() <= this->_signGrade)
	{
		this->_isSigned = true;
		std::cout << "Form " << this->_name << " signed." << std::endl;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form " << form.getName();
	if (form.getIsSigned())
		os << " is";
	else
		os << " is not";
	os << " signed." << std::endl;
	os << "Its grade for signing is " << form.getSignGrade() << "." << std::endl;
	os << "Its grade for executing is " << form.getExecGrade() << "." << std::endl;
	return os;
}
