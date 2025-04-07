/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:16:33 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:16:33 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
	this->brain = new Brain();
	if (this->brain == NULL)
	{
		std::cout << "Cat brain was not created" << std::endl;
		return ;
	}
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
    this->type = copy.type;
	this->brain = new Brain(*copy.brain);
    std::cout << "Cat " << this->type << " was copied" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat " << this->type << " was destroyed" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "Cat " << this->type << " was assigned to " << other.type << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

Brain *Cat::getBrain() const
{
	return (this->brain);
}

void Cat::makeSound() const
{
	std::cout << "Cat " << this->type << " meows" << std::endl;
}