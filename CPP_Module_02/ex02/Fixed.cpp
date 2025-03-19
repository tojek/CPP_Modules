/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:06:09 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/19 14:06:10 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const int value)
{
	this->value = value << Fixed::fractional_bits;
}

Fixed::Fixed(const float value)
{
	this->value = roundf(value * (1 << Fixed::fractional_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed& Fixed::operator = (const Fixed& fixed_operator)
{
	if (this != &fixed_operator)
		this->setRawBits(fixed_operator.getRawBits());
	return (*this);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool operator > (const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits());
}

bool operator < (const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits());
}

bool operator >= (const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() >= b.getRawBits());
}

bool operator <= (const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() <= b.getRawBits());
}

bool operator == (const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() == b.getRawBits());
}

bool operator != (const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() != b.getRawBits());
}

Fixed operator + (const Fixed &a, const Fixed &b)
{
	return (Fixed(a.toFloat() + b.toFloat()));
}

Fixed operator - (const Fixed &a, const Fixed &b)
{
	return (Fixed(a.toFloat() - b.toFloat()));
}

Fixed operator * (const Fixed &a, const Fixed &b)
{
	return (Fixed(a.toFloat() * b.toFloat()));
}

Fixed operator / (const Fixed &a, const Fixed &b)
{
	if (b.toFloat() == 0)
		return (Fixed(0));
	return (Fixed(a.toFloat() / b.toFloat()));
}

Fixed& Fixed::operator ++ (void)
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed& Fixed::operator -- (void)
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

Fixed::~Fixed()
{
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
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}