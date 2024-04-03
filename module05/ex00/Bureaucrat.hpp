#pragma once
#include <string>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade);
		Bureaucrat( Bureaucrat& other );
		Bureaucrat& operator=( Bureaucrat& other );
		~Bureaucrat( void );

		std::string getName( void ) const ;
		int			getGrade( void ) const;
		void		incGrade( int );
		void		decGrade( int );

		class GradeTooHighException {

		}

		class GradeTooLowException {
			
		}
}
		