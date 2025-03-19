/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:06:01 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/19 14:06:02 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << Fixed::fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << Fixed::fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator = (const Fixed& fixed_operator)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed_operator)
		this->setRawBits(fixed_operator.getRawBits());
	return (*this);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << Fixed::fractional_bits));
}

int Fixed::toInt( void ) const
{
	return (this->value >> Fixed::fractional_bits);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}