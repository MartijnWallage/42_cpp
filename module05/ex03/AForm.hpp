/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:25:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 20:11:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class AForm {
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;
	protected:
		virtual void	beExecuted( Bureaucrat const &bureaucrat ) const = 0;
	public:
		AForm( void );
		AForm( std::string name, int const signGrade, int const execGrade);
		AForm( AForm const & );
		AForm& operator=( AForm const & );
		virtual ~AForm( void );

		std::string		getName( void ) const;
		bool			getIsSigned( void ) const;
		int 			getSignGrade( void ) const;
		int 			getExecGrade( void ) const;
		void			beSigned( Bureaucrat& );
		void			execute( Bureaucrat const &executor ) const;\

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, AForm const &);