/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:40:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:18:00 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
protected:
	unsigned int	_energyPoints;
public:
   				ScavTrap( void );
   				ScavTrap( std::string name );
				ScavTrap( const ScavTrap& other );
	ScavTrap&	operator=( const ScavTrap& other );
 			   ~ScavTrap();
    void 		attack(const std::string& target);
    void 		guardGate();
};
