/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:57 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:57 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
	this->brain = new Brain();
	if (this->brain == NULL)
	{
		std::cout << "Dog brain was not created" << std::endl;
		return ;
	}
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    this->type = copy.type;
    this->brain = new Brain(*copy.brain);
    std::cout << "Dog " << this->type << " was copied" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog " << this->type << " was destroyed" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout << "Dog " << this->type << " was assigned to " << other.type << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

std::string Dog::getType() const
{
	return (this->type);
}

Brain *Dog::getBrain() const
{
	return (this->brain);
}

void Dog::makeSound() const
{
	std::cout << "Dog " << this->type << " woofs" << std::endl;
}