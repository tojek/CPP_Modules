/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:41 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:42 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other)
		this->type = other.type;
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
