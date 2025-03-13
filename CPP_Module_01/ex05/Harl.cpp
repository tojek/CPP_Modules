/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:47:10 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/13 14:47:11 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info ( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning ( void )
{
	std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error ( void )
{
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	void (Harl::*complaints[])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "Invalid complaint level" << std::endl;
}