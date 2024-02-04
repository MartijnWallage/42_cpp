#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string newName, Weapon& myWeapon) : name(newName), weapon(myWeapon) {}

void	HumanA::attack( void ) const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}