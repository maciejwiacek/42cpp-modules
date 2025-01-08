#include "Serializer.hpp"
#include <iostream>

int main() {
	Data test;
	test.value = 100;

	uintptr_t serializedAddress =  Serializer::serialize(&test);
	std::cout << serializedAddress << std::endl;
	std::cout << &test << std::endl;
	std::cout << Serializer::serialize(serializedAddress) << std::endl;
}
