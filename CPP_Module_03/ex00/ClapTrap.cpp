#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &claptrap_operator)
{
	if (this != &claptrap_operator)
	{
		this->name = claptrap_operator.name;
		this->hitpoints = claptrap_operator.hitpoints;
		this->energy_points = claptrap_operator.energy_points;
		this->attack_damage = claptrap_operator.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout	<< "ClapTrap " << this->name << " attacks " << target << " causing "
				<< this->attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout	<< "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
}

