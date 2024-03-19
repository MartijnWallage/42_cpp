/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:21 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 17:01:08 by mwallage         ###   ########.fr       */
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
};
