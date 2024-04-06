/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:25:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 19:20:24 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;
		
		RobotomyRequestForm( void );
		void	beExecuted( Bureaucrat const &bureaucrat ) const;
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & );
		RobotomyRequestForm& operator=( RobotomyRequestForm const & );
		~RobotomyRequestForm( void );

		std::string	getTarget( void ) const;

};
