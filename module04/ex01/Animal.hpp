/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:04:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:59:11 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal {
	protected:
		std::string	_type;
		Animal( void );
		Animal( const Animal& );
		Animal&	operator=( const Animal& );
		Animal( std::string type );
	public:
		virtual ~Animal( void );

		std::string		getType( void ) const;
		void			setType( std::string type);
		virtual void	makeSound( void ) const;
};
