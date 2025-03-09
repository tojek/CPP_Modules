#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return (NULL);
	}
	else
	{
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].setName(name);
		return (horde);
	}
}