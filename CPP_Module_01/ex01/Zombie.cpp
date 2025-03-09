#include "Zombie.hpp"

Zombie::Zombie( void )
{
	this->name = "John Doe";
}

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie( void )
{
	std::cout << this->name << " is dead" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->name = name;
}
