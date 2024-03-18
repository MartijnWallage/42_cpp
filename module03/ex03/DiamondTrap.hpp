/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:40:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/18 17:41:28 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
private:
	std::string	_name;
public:
	using FragTrap::_hitPoints;
	using FragTrap::_attackDamage;
	using ScavTrap::_energyPoints;
    using ScavTrap::attack;
    DiamondTrap( void );
    DiamondTrap( std::string name );
    ~DiamondTrap();
    void 		whoAmI() const;
	void		setName( std::string name);
	std::string	getName( void ) const;
	void		displayPoints( void ) const;
};
