#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {
	std::cout << this->_name << " initialized with " << this->_weapon.getType() << std::endl;
	return;
}

HumanA::~HumanA() {
	std::cout << this->_name << " destroyed!" << std::endl;
	return;
}

void HumanA::attack() {
	std::cout << "\033[1m" << this->_name << " attacks with their " << this->_weapon.getType() << "\033[0m" << std::endl;
}