/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:03:20 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:24:26 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	scav1("Adam"), scav2("Harry");
	DiamondTrap	anon, proteus(scav1);
	std::string	name;

	proteus.whoAmI();
	proteus.displayPoints();
	proteus = scav2;
	proteus.whoAmI();
	proteus.displayPoints();
	scav1.displayPoints();
	scav2.displayPoints();
	anon.displayPoints();
	name = scav2.getName();
	scav1.attack(name);
	scav2.takeDamage(10);
	scav2.beRepaired(10);
	scav2.highFiveGuys();
	scav2.whoAmI();
	anon.displayPoints();
	anon.attack(name);
	anon.setName("Alex");
	anon.whoAmI();
	name = scav1.getName();
	for (int i = 0; i < 51; i++)
		anon.attack(name);
	anon.displayPoints();
}