/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:04:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 16:38:33 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal {
	protected:
		std::string	_type;
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& );
		Animal&	operator=( const Animal& );
	public:
		virtual ~Animal( void );

		std::string	getType( void ) const;
		void		setType( std::string type);

		//	This is now a pure virtual function, so that Animal is an abstract class
		virtual void	makeSound( void ) const = 0;
};
