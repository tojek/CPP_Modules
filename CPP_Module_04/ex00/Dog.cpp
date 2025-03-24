#include "Dog.hpp"

Dog::Dog() : type ("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : type(type)
{
    std::cout << "Dog " << this->type << " was born" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    *this = copy;
    std::cout << "Dog " << this->type << " was copied" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog " << this->type << " was destroyed" << std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout << "Dog " << this->type << " was assigned to " << other.type << std::endl;
    this->type = other.type;
    return (*this);
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::setType(std::string type)
{
	this->type = type;
}

void Dog::makeSound() const
{
	std::cout << "Dog " << this->type << " woofs" << std::endl;
}
