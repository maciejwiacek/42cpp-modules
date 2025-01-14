#include "Span.hpp"

int main() {
	try {
		Span sp(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// Test with large number of elements
		Span largeSpan(10000);
		for (int i = 0; i < 10000; ++i) {
			largeSpan.addNumber(i * 2); // Add even numbers
		}
		std::cout << "Shortest span (large): " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span (large): " << largeSpan.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}