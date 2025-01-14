#include "Span.hpp"

int main() {
	try {
		Span sp(5);

		sp.addNumber(-5);
		sp.addNumber(-3);
		sp.addNumber(-17);
		sp.addNumber(-9);
		sp.addNumber(-11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		Span test = sp;
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;

		Span largeSpan(10000);
		for (int i = 0; i < 10000; ++i) {
			largeSpan.addNumber(i * 2);
		}
		std::cout << "Shortest span (large): " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span (large): " << largeSpan.longestSpan() << std::endl;

		Span random(10000);
		random.addNumber(10000, 0);
		std::cout << "Shortest span (random): " << random.shortestSpan() << std::endl;
		std::cout << "Longest span (random): " << random.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}