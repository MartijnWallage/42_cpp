#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZombie");
}