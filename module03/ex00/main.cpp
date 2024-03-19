/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:03:20 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:28:58 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	clap1("Harry"), clap2("Adam");
	ClapTrap	anon, proteus(clap1);
	std::string	name;

	proteus.beRepaired(20);
	proteus = clap2;
	proteus.beRepaired(20);
	name = "Adam";
	clap1.attack(name);
	clap2.takeDamage(10);
	clap2.beRepaired(10);
	name = clap1.getName();
	anon.attack(name);
	anon.setName("Alex");
	anon.takeDamage(20);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
	anon.attack(name);
}