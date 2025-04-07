/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:22 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:22 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
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
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
		this->type = other.type;
    return (*this);
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
	std::cout << "Dog " << this->type << " woofs" << std::endl;
}
