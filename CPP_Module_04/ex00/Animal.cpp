/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:15:14 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/04/07 12:15:14 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal () : type("Unknown")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal (Animal const &copy)
{
    *this = copy;
    std::cout << "Animal " << this->type << " was copied" << std::endl;
}

Animal::~Animal ()
{
    std::cout << "Animal " << this->type << " was destroyed" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
    std::cout << "Animal " << this->type << " was assigned to " << other.type << std::endl;
    this->type = other.type;
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::setType(std::string type)
{
    this->type = type;
}

void Animal::makeSound() const
{
    std::cout << "Animal " << this->type << " makes a sound" << std::endl;
}

