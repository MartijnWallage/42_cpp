/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:35:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/04 18:47:09 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("default"), _signed(false), _execGrade(0), _signGrade(0)
{
}

Form::Form( std::string name, int const signGrade, int const execGrade)
: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
}

Form::Form( Form const & other ) : _signed(other._signed), _execGrade(other._execGrade), _signGrade(other._signGrade)
{
	std::cout << "Form " << _name << " copy constructed" << std::endl;
}

Form& Form::operator=( Form const & other ) {
	_signed = other._signed;
	std::cout << "Form " << _name << " copy assigned" << std::endl;
}

Form::~Form( void ) {
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

std::string const Form::getName( void ) const {
	return _name;
}

bool Form::getSigned( void ) const {
	return _signed;
}

int const Form::getSignGrade( void ) const {
	return _signGrade;
}

int const Form::getExecGrade( void ) const {
	return _execGrade;
}

void Form::beSigned( Bureaucrat& ) {
	
}

void Form::signForm( void ) {

}

const char* Form::GradeTooHighException::what() const throw() {
}

const char* Form::GradeTooLowException::what() const throw() {
}

std::ostream& operator<<( std::ostream& os, Form const &) {

}
