#pragma once

#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	public:
		// CONSTRUCTORS

		MutantStack() : std::stack<T, C>() { };
		MutantStack(const MutantStack& copy) {
			*this = copy;
		}
		~MutantStack() { };

		// OPERATORS

		MutantStack& operator=(const MutantStack& other) {
			if (this != other)
				this = other;
			return *this;
		}


		// ITERATORS

		typedef typename C::iterator iterator;
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		}

		typedef typename C::const_iterator const_iterator;
		const_iterator begin() const {
			return this->c.begin();
		}
		const_iterator end() const {
			return this->c.end();
		}

		typedef typename C::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() {
			return this->c.rbegin();
		}
		reverse_iterator rend() {
			return this->c.rend();
		}

		typedef typename C::const_reverse_iterator const_reverse_iterator;
		reverse_iterator rbegin() const {
			return this->c.rbegin();
		}
		reverse_iterator rend() const {
			return this->c.rend();
		}
};