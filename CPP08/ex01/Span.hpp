#pragma once

#include <iostream>

class Span {
	private:
		std::vector<int> _container;
		unsigned int _items;

		Span();
	public:
		Span(unsigned int items);
		~Span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
};