/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:03:20 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:19:22 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap	scav1("Adam"), scav2("Harry"), scav3(scav2);
	ScavTrap	anon;
	std::string	name;

	name = scav2.getName();
	scav1.attack(name);
	scav2.takeDamage(10);
	scav2.beRepaired(10);
	scav2.guardGate();
	scav3.guardGate();
	scav3 = scav1;
	scav3.guardGate();
	anon.attack(name);
	anon.setName("Alex");
	name = scav1.getName();
	for (int i = 0; i < 51; i++)
		anon.attack(name);
}