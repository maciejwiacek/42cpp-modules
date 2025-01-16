#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./rpn \"[RPN expression]\"" << std::endl;
		return 1;
	}
	RPN rpn(static_cast<std::string>(av[1]));
	rpn.calculate();
}