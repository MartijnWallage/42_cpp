/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:47:11 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 17:43:23 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice( void );
		Ice( Ice const& other );
		Ice& operator=( Ice const& other );
		~Ice( void );

		Ice* clone() const;
		void use(ICharacter& target);
};
