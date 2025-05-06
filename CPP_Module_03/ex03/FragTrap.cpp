#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitpoints = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	std::cout << "FragTrap " << this->name << " has been copied!" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
		std::cout << "FragTrap " << this->name << " has been assigned!" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}
