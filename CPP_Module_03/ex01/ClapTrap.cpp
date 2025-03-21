/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:34:27 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/21 15:34:27 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name(name), hitpoints(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitpoints = other.hitpoints;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
		std::cout << "ClapTrap " << name << " has been assigned!" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitpoints <= 0)
		std::cout	<< "ClapTrap " << this->name << " is dead!" << std::endl;
	else
	{
		if (this->energy_points <= 0)
			std::cout	<< "ClapTrap " << this->name << " has no energy points!" << std::endl;
		else
		{
			this->energy_points--;
			std::cout	<< "ClapTrap " << this->name << " attacks " << target << " causing "
						<< this->attack_damage << " points of damage!" << std::endl;
		}
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitpoints < amount)
	{
		this->hitpoints = 0;
		std::cout	<< "ClapTrap " << this->name << " takes " << amount << " points of damage and dies!" << std::endl;
	}
	else
	{
		this->hitpoints -= amount;
		std::cout	<< "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points <= 0)
		std::cout	<< "ClapTrap " << this->name << " has no energy points!" << std::endl;
	else
	{
		this->energy_points--;
		this->hitpoints += amount;
		std::cout	<< "ClapTrap " << this->name << " is repaired for " << amount << " points!" << std::endl;
	}
}
