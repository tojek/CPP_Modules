/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:47:29 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/13 14:47:30 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

Harl::Harl( void )
{
	std::cout << "Harl is coming!" << std::endl;
}

Harl::~Harl( void )
{
	std::cout << "Harl is leaving!" << std::endl;
}

void Harl::debug ( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info ( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning ( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error ( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*complaints[])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	int i = 0;
	for (; i < 4; i++)
	{
		if (levels[i] == level)
		{
			break ;
		}
	}
	switch (i)
	{
		case 0:
			(this->*complaints[0])();
			__attribute__((fallthrough));
		case 1:
			(this->*complaints[1])();
			__attribute__((fallthrough));
		case 2:
			(this->*complaints[2])();
			__attribute__((fallthrough));
		case 3:
			(this->*complaints[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
	// std::cout << "Invalid complaint level" << std::endl;
}