/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:19:44 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/28 16:53:45 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void		Zombie::setName(const std::string& name) {
	_name = name;
}

std::string	Zombie::getName() const {
	return _name;
}

void		Zombie::announce( void ) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name) : _name(name) {}

Zombie::~Zombie( void ) {
	std::cout << _name << " is destroyed." << std::endl;
}
