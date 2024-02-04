#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombies;
	
	zombies = zombieHorde(10, "zombietwin");
	delete[] zombies;
	return 0;
}
