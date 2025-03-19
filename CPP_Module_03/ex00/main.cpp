#include "ClapTrap.hpp"

int main()
{
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

    return (0);
}