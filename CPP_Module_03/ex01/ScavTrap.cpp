#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	std::cout << "ScavTrap " << this->name << " has been copied!" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
		std::cout << "ScavTrap " << this->name << " has been assigned!" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitpoints <= 0)
		std::cout	<< "ScavTrap " << this->name << " is dead!" << std::endl;
	else
	{
		if (this->energy_points <= 0)
			std::cout	<< "ScavTrap " << this->name << " has no energy points!" << std::endl;
		else
		{
			this->energy_points--;
			std::cout	<< "ScavTrap " << this->name << " attacks " << target << " causing "
						<< this->attack_damage << " points of damage!" << std::endl;
		}
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode!" << std::endl;
}