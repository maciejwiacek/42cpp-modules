#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string _name;
	unsigned int _hitPts;
	unsigned int _energyPts;
	unsigned int _attackDmg;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& copy);
	virtual ~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif