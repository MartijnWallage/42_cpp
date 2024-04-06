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

#include "AForm.hpp"

AForm::AForm( void )
: _name("default"), _isSigned(false), _signGrade(1), _execGrade(1)
{
	std::cout << "AForm " << _name << " created." << std::endl;
}

AForm::AForm( std::string name, int const signGrade, int const execGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_signGrade > 150)
		throw AForm::GradeTooLowException();
	if (this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (this->_execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm " << _name << " created." << std::endl;
}

AForm::AForm( AForm const & other )
: _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "AForm " << _name << " copy constructed" << std::endl;
}

AForm& AForm::operator=( AForm const & other ) {
	_isSigned = other._isSigned;
	std::cout << "AForm " << _name << " copy asisSigned" << std::endl;
	return *this;
}

AForm::~AForm( void ) {
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

std::string AForm::getName( void ) const {
	return _name;
}

bool AForm::getIsSigned( void ) const {
	return _isSigned;
}

int AForm::getSignGrade( void ) const {
	return _signGrade;
}

int AForm::getExecGrade( void ) const {
	return _execGrade;
}

void AForm::beSigned( Bureaucrat& k ) {
	if (k.getGrade() <= this->_signGrade) {
		this->_isSigned = true;
		std::cout << "AForm " << this->_name << " signed." << std::endl;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute( Bureaucrat const &executor ) const {
	if (this->_isSigned == false)
		throw AForm::FormNotSignedException(); 
	if (executor.getGrade() > this->_execGrade) {
		throw AForm::GradeTooLowException();
	} else {
		this->beExecuted(executor);
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "form not signed";
}

std::ostream& operator<<( std::ostream& os, AForm const & AForm) {
	os << "AForm " << AForm.getName();
	if (AForm.getIsSigned())
		os << " is";
	else
		os << " is not";
	os << " signed." << std::endl;
	os << "Its grade for signing is " << AForm.getSignGrade() << "." << std::endl;
	os << "Its grade for executing is " << AForm.getExecGrade() << "." << std::endl;
	return os;
}
