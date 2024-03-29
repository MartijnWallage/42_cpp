/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:17:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/20 18:55:09 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
	private:
		Brain	*_brain;
	public:
		Dog( void );
		Dog( const Dog& );
		Dog&	operator=( const Dog& );
		~Dog( void );

		void	makeSound( void ) const;
		Brain*	getBrain( void ) const;
};