#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator = (const ScavTrap &other);
		~ScavTrap();

		void	attack(const std::string& target);
	protected:
		void	guardGate();
};

#endif