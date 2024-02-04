#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombies;
	
	zombies = zombieHorde(16, "zombietwin");
	delete[] zombies;
	return 0;
}