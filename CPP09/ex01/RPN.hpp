#pragma once

#include <list>
#include <iostream>

class RPN {
	private:
		std::stack<int> _stack;
		std::string _input;
	public:
		RPN(const std::string& input);
		~RPN();
		void calculate();
};