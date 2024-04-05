/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:59:16 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/05 16:34:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) : _name("K."), _grade(150)
{
	std::cout << "Bureaucrat K. hired" << std::endl;
}

Bureaucrat::Bureaucrat( std::string& name, int grade) : _name(name), _grade(grade)
{
	checkGrade();
	std::cout << "Bureaucrat " << _name << " hired" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat " << _name << " copy constructed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) 
{
	// cannot copy const name
	_grade = other._grade;
	std::cout << "Bureaucrat " << _name << " copy assigned" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat " << _name << " released" << std::endl; 
}

std::string Bureaucrat::getName( void ) const {
	return _name;
}

int	Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::incGrade( void) {
	_grade--;
	checkGrade();
	std::cout << "Grade of bureaucrat " << _name << " increased" << std::endl;
}

void Bureaucrat::decGrade( void ) {
	_grade++;
	checkGrade();
	std::cout << "Grade of bureaucrat " << _name << " decreased" << std::endl;
}

void Bureaucrat::checkGrade( void ) const {
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream&	operator<<( std::ostream &os, Bureaucrat const & bureaucrat ) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm( Form & form ) {
	try {
		form.beSigned( *this );
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << this->_name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}