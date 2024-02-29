/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:52 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 14:58:53 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {};

const std::string&	Weapon::getType() const {
	return _type;
}

void Weapon::setType( std::string newType ) {
	_type = newType;
}

Weapon::~Weapon( void ) {}
