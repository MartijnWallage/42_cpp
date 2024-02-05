#pragma	once

#include "Weapon.hpp"
#include <string>

class	HumanA {
	public:
		HumanA( std::string name, Weapon& myWeapon);
		void	attack( void ) const;
	private:
		std::string	name;
		Weapon&		weapon;
		
};
