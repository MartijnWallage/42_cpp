/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:17:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 16:32:03 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog( void );
		Dog( const Dog& );
		Dog&	operator=( const Dog& );
		~Dog( void );

		void	makeSound( void ) const;
};