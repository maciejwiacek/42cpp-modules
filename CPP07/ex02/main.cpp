#include "Array.hpp"

int main() {
	Array<int> numbers(15);
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << std::endl;
	try {
		numbers[16];
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}