/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:18 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:18 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
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
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
		this->type = other.type;
    return (*this);
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "Cat " << this->type << " meows" << std::endl;
}