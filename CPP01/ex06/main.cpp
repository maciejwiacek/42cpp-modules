#include "Harl.hpp"

void printStatement(std::string level) {
	Harl harl;
	int i = 0;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++) {
		if (levels[i] == level)
			break;
	}

	switch (i) {
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int ac, char **av) {
	Harl harl;

	if (ac < 2)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (1);
	}
	printStatement(av[1]);
	return 0;
}