#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("weak guy"), _hitPts(10), _energyPts(10), _attackDmg(0) {
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPts(10), _energyPts(10), _attackDmg(0) {
	std::cout << "ClapTrap name constructor called!\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "ClapTrap copy constructor called!\n";
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	std::cout << "ClapTrap assignment operator constructor called!\n";
	if (this != &copy) {
		this->_name = copy._name;
		this->_attackDmg = copy._attackDmg;
		this->_energyPts = copy._energyPts;
		this->_hitPts = copy._hitPts;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap deconstructor called!\n";
}

void ClapTrap::attack(const std::string &target) {
	if (this->_hitPts > 0 && this->_energyPts > 0) {
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDmg << " points of damage!\n";
		this->_energyPts--;
	}
	else if (this->_energyPts == 0)
		std::cout << "ClapTrap " << this->_name << " has not enough energy points to attack " << target << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is dead\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPts > amount) {
		this->_hitPts -= amount;
		std::cout << "ClapTrap " << this->_name << " got attacked and took " << amount << " damage\n";
		std::cout << "Now he has " << this->_hitPts << " hit points\n";
	} else if (this->_hitPts > 0) {
		this->_hitPts = 0;
		std::cout << "ClapTrap " << this->_name << " got attacked and took " << amount << " damage\n";
		std::cout << "Now he's dead :(\n";
	} else {
		std::cout << "Stop beating the dead guy!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPts > 0) {
		this->_hitPts += amount;
		this->_energyPts--;
		std::cout << "ClapTrap " << this->_name << " healed himself by " << amount << " hit points\n";
		std::cout << "Now he has " << this->_hitPts << " hit points\n";
	} else {
		std::cout << "ClapTrap " << this->_name << " has not enough energy to heal\n";
	}
}
