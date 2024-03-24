#include <iostream>
#include "ICharacter.hpp"

ICharacter::ICharacter( void )
{
	std::cout << "ICharacter constructed!" << std::endl;
}

ICharacter::ICharacter( ICharacter const& )
{
	std::cout << "ICharacter copied!" << std::endl;
}

ICharacter& ICharacter::operator=( ICharacter const& )
{
	std::cout << "ICharacter assignment copied!" << std::endl;
	return *this;
}