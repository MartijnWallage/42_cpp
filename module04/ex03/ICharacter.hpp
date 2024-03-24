/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:44:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 19:08:45 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AMateria.hpp"

class ICharacter {
	protected:
		ICharacter( void );
		ICharacter( ICharacter const& );
		ICharacter& operator=( ICharacter const& );
	public:
		virtual ~ICharacter( void ) {}
		virtual std::string const & getName() const = 0;
		virtual void equip( AMateria* m) = 0;
		virtual void unequip( int idx ) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;
};
