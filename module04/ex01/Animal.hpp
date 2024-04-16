/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:04:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 16:44:38 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal {
	protected:
		std::string	_type;
		Animal( void );
		Animal( const Animal& );
		Animal( std::string type );
		Animal&	operator=( const Animal& );
	public:
		virtual ~Animal( void );

		std::string		getType( void ) const;
		void			setType( std::string type );
		virtual void	makeSound( void ) const;
};
