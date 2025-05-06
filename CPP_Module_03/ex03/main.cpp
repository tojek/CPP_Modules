#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap fragtrap("Fragtrap");

    // Test basic functionality
    fragtrap.attack("Enemy");
    fragtrap.takeDamage(50);
    fragtrap.beRepaired(30);
    fragtrap.highFivesGuys();

    // Test death scenario
    fragtrap.takeDamage(200);      // Should kill the FragTrap
    fragtrap.attack("Enemy");      // Should fail - no health
    fragtrap.highFivesGuys();      // Should still work even when dead

    return (0);
}