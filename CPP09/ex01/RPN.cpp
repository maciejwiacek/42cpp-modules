#include "RPN.hpp"

RPN::RPN(const std::string &input): _input(input) {}

RPN::~RPN() {}

void RPN::calculate() {
	for (std::string::const_iterator it = this->_input.cbegin(); it != this->_input.cend(); it++) {
		if (*it == ' ')
			continue;

		if (*it == '+') {
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(a + b);
		} else if (*it == '-') {
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(a - b);
		} else if (*it == '/') {
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(a / b);
		} else if (*it == '*') {
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(a * b);
		} else if (std::isdigit(*it)) {
			_stack.push(*it - '0');
		} else {
			std::cout << "Error\n";
			return;
		}
	}

	if (_stack.size() == 1) {
		std::cout << _stack.top() << std::endl;
	} else {
		std::cout << "Error\n";
	}
}