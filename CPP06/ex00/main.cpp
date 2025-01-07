#include "ScalarConverter.hpp"

void printEnumValue(int type) {
	std::cout << "Value type: ";
	switch (type) {
		case N_A_N:   std::cout << "N_A_N\n"; break;
		case INF:     std::cout << "INF\n"; break;
		case CHAR:    std::cout << "CHAR\n"; break;
		case INT:     std::cout << "INT\n"; break;
		case DOUBLE:  std::cout << "DOUBLE\n"; break;
		case FLOAT:   std::cout << "FLOAT\n"; break;
		case ERR:     std::cout << "ERR\n"; break;
		default:      std::cout << "Unknown type\n"; break;
	}
}

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Usage: ./converter <input>\n";
		return 1;
	}
	std::string input = av[1];
	ScalarConverter conv(input);

	return (0);
}
