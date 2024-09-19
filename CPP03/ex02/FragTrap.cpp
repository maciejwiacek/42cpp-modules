#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name): ClapTrap() {
	this->_name = name;
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout << "FragTrap name constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "FragTrap copy constructor called\n";
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
	std::cout << "FragTrap assignment operator constructor called\n";
	this->_name = copy._name;
	this->_hitPts = copy._hitPts;
	this->_energyPts = copy._energyPts;
	this->_attackDmg = copy._attackDmg;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap deconstructor called\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " is high fiving you!\n";
}