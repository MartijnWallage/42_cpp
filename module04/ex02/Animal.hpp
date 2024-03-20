/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:04:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/20 19:09:42 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal {
	protected:
		std::string	_type;
	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& );
		Animal&	operator=( const Animal& );
		virtual ~Animal( void );

		std::string	getType( void ) const;
		void		setType( std::string type);
		virtual void	makeSound( void ) const = 0;
};
