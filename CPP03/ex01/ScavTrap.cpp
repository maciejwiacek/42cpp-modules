#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called\n";
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	this->_keeperMode = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap() {
	std::cout << "ScavTrap name constructor called\n";
	this->_name = name;
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	this->_keeperMode = false;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "ScavTrap copy constructor called\n";
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	std::cout << "ScavTrap assignment operator constructor called\n";
	this->_name = copy._name;
	this->_hitPts = copy._hitPts;
	this->_energyPts = copy._energyPts;
	this->_attackDmg = copy._attackDmg;
	this->_keeperMode = copy._keeperMode;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap deconstructor called\n";
}

void ScavTrap::attack(const std::string &name) {
	if (this->_hitPts > 0 && this->_energyPts > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << name;
		std::cout << ", causing " << this->_attackDmg << " points of damage!\n";
		this->_energyPts--;
	}
	else if (this->_energyPts == 0)
		std::cout << "ScavTrap " << this->_name << " has not enough energy points to attack " << name << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is dead\n";
}

void ScavTrap::guardGate() {
	this->_keeperMode = true;
	std::cout << "ScavTrap " << this->_name << " is now in guarding mode\n";
}