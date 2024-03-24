/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:54:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 18:42:32 by mwallage         ###   ########.fr       */
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

	std::string const & getName() const;
	void equip( AMateria* m);
	void unequip( int idx );
	void use( int idx, ICharacter& target );
};
