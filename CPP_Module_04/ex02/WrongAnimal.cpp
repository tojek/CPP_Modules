/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:16:49 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:16:50 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal () : type("Wrong")
{
	std::cout << "Wrong Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal (std::string type) : type(type)
{
	std::cout << "Wrong Animal " << this->type << " was born" << std::endl;
}

WrongAnimal::WrongAnimal (WrongAnimal const &copy)
{
	*this = copy;
	std::cout << "Wrong Animal " << this->type << " was copied" << std::endl;
}

WrongAnimal::~WrongAnimal ()
{
	std::cout << "Wrong Animal " << this->type << " was destroyed" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "Wrong Animal " << this->type << " was assigned to " << other.type << std::endl;
	this->type = other.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal " << this->type << " makes a sound" << std::endl;
}
