/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:46:25 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/13 14:46:26 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 2;

    Zombie* horde = zombieHorde(N, "Walker");

	if (horde == NULL)
	{
		std::cout << "Memory allocation failed." << std::endl;
		return (1);
	}

    if (horde)
    {
        for (int i = 0; i < N; i++)
            horde[i].announce();
        delete[] horde;
    }

    return 0;
}
