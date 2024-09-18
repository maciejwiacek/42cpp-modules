#include "ClapTrap.hpp"

int main()
{
	std::cout << "----- ClapTrap -----\n";
	ClapTrap a;
	ClapTrap b("Mirek Mechanik");
	ClapTrap c;
	c = b;

	std::cout << "----- Let the fight begin -----\n";
	a.attack("Mirek Mechanik");
	b.takeDamage(0);
	b.beRepaired(2);
	c.attack("the random guy");
	c.takeDamage(100);
	b.beRepaired(100);

	std::cout << "----- Let's leave this place -----\n";
}