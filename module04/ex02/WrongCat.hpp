/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:21 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 16:45:28 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat( void );
		WrongCat( const WrongCat& );
		WrongCat&	operator=( const WrongCat& );
		~WrongCat( void );

		void	makeSound( void ) const;
};
