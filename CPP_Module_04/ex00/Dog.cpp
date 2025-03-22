#include "Dog.hpp"

Dog::Dog() : type Dog
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(sdt::string type) : type(type)
{
    std::cout << "Dog " << this->type << " was born" << std::endl;
}

Dog::Dog(Dog const &copy)
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

