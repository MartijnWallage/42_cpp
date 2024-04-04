/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:25:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/04 18:45:57 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class Form {
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
	public:
		Form( void );
		Form( std::string name, int const signGrade, int const execGrade);
		Form( Form const & );
		Form& operator=( Form const & );
		~Form( void );

		std::string const	getName( void ) const;
		bool				getSigned( void ) const;
		int const			getSignGrade( void ) const;
		int const			getExecGrade( void ) const;

		void				beSigned( Bureaucrat& );
		void				signForm( void );

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, Form const &);