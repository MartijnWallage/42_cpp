/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:21 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/20 18:55:24 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	private:
		Brain	*_brain;
	public:
		Cat( void );
		Cat( const Cat& );
		Cat&	operator=( const Cat& );
		~Cat( void );

		void	makeSound( void ) const;
		Brain*	getBrain( void ) const;
};
