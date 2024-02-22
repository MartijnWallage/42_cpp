/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:01 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:20:03 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void		Zombie::setName(const std::string& nname) {
	name = nname;
}

std::string	Zombie::getName() const {
	return name;
}

void		Zombie::announce( void ) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( void ) : name("") {}

Zombie::Zombie( std::string name) : name(name) {}

Zombie::~Zombie( void ) {
	std::cout << name << " is destroyed." << std::endl;
}
