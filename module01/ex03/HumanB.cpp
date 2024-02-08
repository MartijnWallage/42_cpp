#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string newName ) : name(newName) {
	weapon = NULL;
}


void	HumanB::setWeapon( Weapon& newWeapon ) {
	weapon = &newWeapon;
}

void	HumanB::attack( void ) const {
	if (weapon) {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else
		std::cout << name << " has no weapon!" << std::endl;
}