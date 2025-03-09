#include "Zombie.hpp"

int main()
{
    int N = 2;

    Zombie* horde = zombieHorde(N, "Walker");

	if (horde == NULL)
	{
		std::cout << "Memory allocation failed." << std::endl;
		return (1);
	}

    if (horde)
    {
        for (int i = 0; i < N; i++)
            horde[i].announce();
        delete[] horde;
    }

    return 0;
}
