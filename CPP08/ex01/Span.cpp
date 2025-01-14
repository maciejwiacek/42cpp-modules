#include "Span.hpp"

Span::Span(unsigned int items) : _items(items) {
	_container.reserve(items);
}

Span::~Span() { }

void Span::addNumber(int number) {
	if (_container.size() >= _items)
		throw std::runtime_error("Span is full");
	_container.push_back(number);
}

int Span::shortestSpan() {
	if (_container.size() < 2)
		throw std::runtime_error("Couldn't get shortest span (not enough items)");

	std::vector<int> tmp = _container;
	std::sort(tmp.begin(), tmp.end());

	int result = std::numeric_limits<int>::max();
	for(size_t i = 1; i < tmp.size(); i++)
		result = std::min(result, tmp[i] - tmp[i - 1]);

	return result;
}

int Span::longestSpan() {
	if (_container.size() < 2)
		throw std::runtime_error("Couldn't get longest span (not enough items)");

	int min = *std::min_element(_container.begin(), _container.end());
	int max = *std::max_element(_container.begin(), _container.end());

	return max - min;
}
