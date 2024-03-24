/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:54:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 18:04:06 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter {
private:
	std::string	_name;
	AMateria	*_inventory[4];
public:
	Character( void );
	Character( std::string const name );
	Character( Character const& other );
	Character& operator=( Character const& other );
	~Character( void );

	std::string const & getName();
	void equip( AMateria* m);
	void unequip( int idx );
	void use( int idx, ICharacter& target ) = 0;
};
