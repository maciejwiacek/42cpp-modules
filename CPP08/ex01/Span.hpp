#pragma once

#include <iostream>

class Span {
	private:
		std::vector<int> _container;
		unsigned int _items;

		Span();
	public:
		Span(unsigned int items);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		void addNumber(unsigned int range, time_t time);
		int shortestSpan();
		int longestSpan();

		void printSpan();
};