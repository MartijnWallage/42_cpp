#include "Weapon.hpp"

const std::string&	Weapon::getType() const {
	return type;
}

void Weapon::setType( std::string newType ) {
	type = newType;
}

