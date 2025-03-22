#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(sdt::string const type) : type(type)
{
    std::cout << "Cat " << this->type << " was born" << std::endl;
}

Cat::Cat(Cat const &copy)
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

