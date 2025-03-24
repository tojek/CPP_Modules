#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const type) : type(type)
{
    std::cout << "Cat " << this->type << " was born" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
    *this = copy;
    std::cout << "Cat " << this->type << " was copied" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat " << this->type << " was destroyed" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "Cat " << this->type << " was assigned to " << other.type << std::endl;
    this->type = other.type;
    return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::setType(std::string type)
{
	this->type = type;
}

void Cat::makeSound() const
{
	std::cout << "Cat " << this->type << " meows" << std::endl;
}