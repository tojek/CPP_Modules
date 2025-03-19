#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("Claptrap");

	claptrap.attack("Enemy");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	return (0);
}