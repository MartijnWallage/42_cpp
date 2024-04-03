#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("K."), _grade(150)
{
	std::cout << "Bureaucrat K. hired" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150) {
		throw GradeTooHighException;
	} else if (grade < 1) {
		throw GradeTooLowException;
	}
	std::cout << "Bureaucrat " << _name << " hired" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other.name), _grade(other.grade)
{
	std::cout << "Bureaucrat " << _name << " copy constructed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) 
{
	_name = other.name;
	_grade = other.grade;
	std::cout << "Bureaucrat " << _name << " copy assigned" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat released" << std::endl; 
}

std::string Bureaucrat::getName( void ) const {
	return _name;
}

int	Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::incGrade( int nbr ) {
	
	if (grade - nbr < 1) {
		throw GradeTooHighException;
	}
}

void Bureaucrat::decGrade( int grade ) {
	if (grade < 150) {
		_grade++;
	} else {
		throw GradeTooLowException;
	}
}
