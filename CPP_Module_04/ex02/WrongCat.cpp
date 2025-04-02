
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	*this = copy;
	std::cout << "WrongCat " << this->type << " was copied" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << this->type << " was destroyed" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	std::cout << "WrongCat " << this->type << " was assigned to " << other.getType() << std::endl;
	this->setType(other.getType());
	return (*this);
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat " << this->type << " says damb-da-da-damba-dam" << std::endl;
}
