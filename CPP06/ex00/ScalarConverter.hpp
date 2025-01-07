#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

typedef enum Type {
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	INF = 4,
	N_A_N = 5,
	ERR = 6
} Type;

class ScalarConverter {
	private:
		const std::string _input;
		char _char;
		int _int;
		float _float;
		double _double;

		ScalarConverter();

		void convertChar();
		void convertInt();
		void convertDouble();
		void convertFloat();

		int validateInput();
		void convert(int inputType);
		void print(int type);

	public:
		ScalarConverter(const std::string input);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter operator=(const ScalarConverter& other);
		~ScalarConverter();

		void print();

		class ErrorException : public std::exception {
				virtual const char *what() const throw();
		};
};
