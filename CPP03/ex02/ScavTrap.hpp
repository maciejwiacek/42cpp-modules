#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
private:
	bool _keeperMode;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& copy);
	virtual ~ScavTrap();
	void attack(const std::string& name);
	void guardGate();
};

#endif