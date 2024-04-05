/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:25:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/05 16:25:23 by mwallage         ###   ########.fr       */
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
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;
	public:
		Form( void );
		Form( std::string name, int const signGrade, int const execGrade);
		Form( Form const & );
		Form& operator=( Form const & );
		~Form( void );

		std::string const	getName( void ) const;
		bool				getIsSigned( void ) const;
		int 				getSignGrade( void ) const;
		int 				getExecGrade( void ) const;

		void				beSigned( Bureaucrat& );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, Form const &);