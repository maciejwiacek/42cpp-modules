#pragma once

#include <iostream>

class Brain {
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain& other);
	virtual ~Brain();
	std::string getIdea(int i);
	void setIdea(int i, std::string idea);
};