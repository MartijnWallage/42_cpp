/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:49:17 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:27:28 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ClapTrap {
private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
				ClapTrap( void );
				ClapTrap( std::string name);
				ClapTrap( const ClapTrap& other );
	ClapTrap&	operator=( const ClapTrap& other );
				~ClapTrap( void );
	void		setName( const std::string& name );
	std::string	getName( void ) const;	
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};
