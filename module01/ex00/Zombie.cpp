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

Zombie::Zombie( std::string name) : name(name) {}

Zombie::~Zombie( void ) {
	std::cout << name << " is destroyed." << std::endl;
}
