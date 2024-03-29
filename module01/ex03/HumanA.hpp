/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:30 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 14:59:45 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include "Weapon.hpp"
#include <string>

class	HumanA {
	public:
					HumanA( std::string name, Weapon& myWeapon);
		void		attack( void ) const;
	private:
		std::string	_name;
		Weapon&		_weapon;
		
};
