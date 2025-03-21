/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:34:30 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/21 15:34:30 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap claptrap("Claptrap");

    // Test regular
    claptrap.attack("Enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    // Test energy points
    for (int i = 0; i < 8; ++i)
        claptrap.attack("Enemy");  // Should deplete remaining energy points

    claptrap.attack("Enemy");      // Should fail - no energy points
    claptrap.beRepaired(5);        // Should fail - no energy points

    // Test death scenario
    claptrap.takeDamage(20);       // Should kill the ClapTrap
    claptrap.attack("Enemy");      // Should fail - no health

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scavtrap("Scavtrap");

    scavtrap.attack("Enemy");
    scavtrap.takeDamage(30);
    scavtrap.beRepaired(20);
    scavtrap.guardGate();

    return (0);
}