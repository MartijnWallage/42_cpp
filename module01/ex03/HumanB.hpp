#pragma	once

#include "Weapon.hpp"
#include <string>

class	HumanB {
	public:
		HumanB( std::string name );
		void	attack( void ) const;
		void	setWeapon( Weapon& newWeapon );
	private:
		Weapon*		weapon;
		std::string	name;
		
};
