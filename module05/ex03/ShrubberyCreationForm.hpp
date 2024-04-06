/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:25:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 17:54:34 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class ShrubberyCreationForm : public AForm {
	private:
		std::string	_target;
		
		ShrubberyCreationForm( void );
		void	beExecuted( Bureaucrat const &bureaucrat ) const;
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & );
		ShrubberyCreationForm& operator=( ShrubberyCreationForm const & );
		~ShrubberyCreationForm( void );

		std::string	getTarget( void ) const;

};
