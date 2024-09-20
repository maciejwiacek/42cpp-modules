#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called\n";
	*this = copy;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignment operator called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i].assign(other._ideas[i]);
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called\n";
}

std::string Brain::getIdea(int i) {
	if (i < 100)
		return this->_ideas[i];
	std::cout << "Index out of range\n";
	return "";
}

void Brain::setIdea(int i, std::string idea) {
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cout << "Index out of range\n";
}