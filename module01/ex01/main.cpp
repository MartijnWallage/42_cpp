/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:19:53 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 14:51:02 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombies;
	
	zombies = zombieHorde(10, "zombietwin");
	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}
