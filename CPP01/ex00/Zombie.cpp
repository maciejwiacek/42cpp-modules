#include "Zombie.hpp"

Zombie::Zombie(void) {
	return;
}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " is being destructed..." << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl;
}