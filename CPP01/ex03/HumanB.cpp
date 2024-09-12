#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(nullptr) {
	std::cout << this->_name << " initialized with no weapon!" << std::endl;
	return;
}

HumanB::~HumanB() {
	std::cout << this->_name << " destroyed!" << std::endl;
	return;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() {
	std::cout << "\033[1m" << this->_name << " attacks with their " << this->_weapon->getType() << "\033[0m" << std::endl;
}