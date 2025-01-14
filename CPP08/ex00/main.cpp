#include "easyfind.hpp"

int main() {
	std::vector<int> values;
	for (int i = 0; i < 10; i++)
		values.push_back(i);
	std::cout << "Values before:\n";
	for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	int* address = easyfind(values, 2);
	*address = 10;
	std::cout << "Values after:\n";
	for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}