#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade);
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat( void );

		std::string getName( void ) const ;
		int			getGrade( void ) const;
		void		incGrade( int );
		void		decGrade( int );

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw() {
				std::cout << "Grade is too high!" << std::endl;
				return NULL;
			}
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw() {
				std::cout << "Grade is too low!" << std::endl;
				return NULL;
			}
		};
};
		