#include "Iter.hpp"
#include <iostream>
#include <cstddef>

void printElement(int element) {
	std::cout << element << " ";
}

void multiplyByTwo(int& element) {
	element *= 2;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	size_t arrLength = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original array: ";
	::iter(arr, arrLength, printElement);
	std::cout << std::endl;

	::iter(arr, arrLength, multiplyByTwo);

	std::cout << "Modified array: ";
	::iter(arr, arrLength, printElement);
	std::cout << std::endl;

	return 0;
}