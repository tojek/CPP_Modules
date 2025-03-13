/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:46:31 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/13 14:46:32 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return (NULL);
	}
	else
	{
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].setName(name);
		return (horde);
	}
}