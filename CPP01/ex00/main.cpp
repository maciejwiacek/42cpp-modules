#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main() {
	Zombie *zombie = newZombie("Jerzy");
	zombie->announce();
	randomChump("Stefan");
	delete zombie;
}