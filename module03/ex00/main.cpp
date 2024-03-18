/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:03:20 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/18 14:31:07 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	clap1("Harry"), clap2("Adam");
	ClapTrap	anon;
	std::string	name;

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