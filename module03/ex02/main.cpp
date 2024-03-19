/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:03:20 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:14:55 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	scav1("Adam"), scav2("Harry");
	FragTrap	anon;
	FragTrap	cpy(scav2);
	std::string	name;

	cpy.highFiveGuys();
	anon = scav1;
	name = scav2.getName();
	scav1.attack(name);
	scav2.takeDamage(10);
	scav2.beRepaired(10);
	scav2.highFiveGuys();
	anon.attack(name);
	anon.setName("Alex");
	name = scav1.getName();
	for (int i = 0; i < 101; i++)
		anon.attack(name);
}