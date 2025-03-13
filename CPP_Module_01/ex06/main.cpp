/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:47:36 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/13 14:47:37 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return 1;
	}
	Harl harl;
	harl.complain(argv[1]);

	return 0;
}