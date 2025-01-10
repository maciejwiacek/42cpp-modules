#pragma once

#include <iostream>

template <typename T>
class Array {
	private:
		T* _arr;
		unsigned int _n;
	public:
		Array(): _n(0) {
			this->_arr = new T[this->_n];
		}

		Array(unsigned int n): _n(n) {
			this->_arr = new T[this->_n];
		}

		Array(const Array& other): _n(other._n) {
			*this = other;
		}

		Array &operator=(const Array& other) {
			if (this->_arr)
				delete [] this->_arr;
			if (other._n) {
				this->_n = other._n;
				this->_arr = new T[this->_n];
				for (int i = 0; i < this->_n; i++)
					this->_arr[i] = other._arr[i];
			}
			return *this;
		}

		~Array() {
			if (this->_arr)
				delete [] this->_arr;
		}

		T &operator[](unsigned int i) {
			if (i >= this->_n || !this->_arr) {
				std::cout << "Index out of range\n";
				throw IndexException();
			}
			return this->_arr[i];
		}

		class IndexException : public std::exception {
				virtual const char *what() const throw() {
					return "Index out of range\n";
				}
		};

		unsigned int size() {
			return this->_n;
		}
};