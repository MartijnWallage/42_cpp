/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:40 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 15:02:02 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include "Weapon.hpp"
#include <string>

class	HumanB {
public:
				HumanB( std::string name );
	void		attack( void ) const;
	void		setWeapon( Weapon& newWeapon );
private:
	Weapon*		_weapon;
	std::string	_name;
};
