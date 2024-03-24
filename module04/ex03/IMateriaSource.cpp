#include <iostream>
#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void )
{
	std::cout << "IMateriaSource constructed!" << std::endl;
}

IMateriaSource::IMateriaSource( IMateriaSource const& )
{
	std::cout << "IMateriaSource copy constructed!" << std::endl;
}

IMateriaSource& 	IMateriaSource::operator=( IMateriaSource const& )
{
	std::cout << "IMateriaSource copy assigned!" << std::endl;
	return *this;
}
