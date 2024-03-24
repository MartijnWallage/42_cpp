/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:43:33 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 17:44:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria {
	public:
		Cure( void );
		Cure( Cure const& other );
		Cure& operator=( Cure const& other );
		~Cure( void );

		Cure* clone() const;
		void use(ICharacter& target);
};
