#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const std::string input): _input(input) {
	int inputType = this->validateInput();
	this->_double = std::atof(this->_input.c_str());
	try {
		this->convert(inputType);
	} catch (std::exception& e) {
		std::cout << e.what();
		return;
	}
	this->print(inputType);
}

ScalarConverter::~ScalarConverter() {
}

int ScalarConverter::validateInput() {
	// Check for nan
	if (!this->_input.compare("nan"))
		return N_A_N;
	// Check for inf
	if (!this->_input.compare("+inf") || !this->_input.compare("-inf")
		|| !this->_input.compare("+inff") || !this->_input.compare("-inff"))
		return INF;
	// Check for char that is not a digit
	if (this->_input.length() == 1 && isalpha(this->_input[0]))
		return CHAR;
	// Check for multiple signs
	if (this->_input.find_first_of("+-") != this->_input.find_last_of("+-"))
		return ERR;
	// Check for integers
	if (this->_input.find_first_not_of("+-0123456789") == std::string::npos)
		return INT;
	// Check for doubles
	if (this->_input.find_first_not_of("+-0123456789.") == std::string::npos) {
		// Check for 0..0, .0, 0.
		if (this->_input.find_first_of(".") != this->_input.find_last_of(".") ||
			this->_input[0] == '.' ||
			!isdigit(this->_input[this->_input.find_first_of(".") + 1]))
			return ERR;
		else
			return DOUBLE;
	}
	// Check for floats
	if (this->_input.find_first_not_of("+-0123456789.f") == std::string::npos) {
		// Check for 0..0, .0, 0., 0.1ff, 0.1f0
		if (this->_input.find_first_of(".") != this->_input.find_last_of(".") ||
		    this->_input[0] == '.' ||
		    !isdigit(this->_input[this->_input.find_first_of(".") + 1]) ||
			this->_input.find_first_of("f") != this->_input.find_last_of("f") ||
			this->_input[this->_input.find_first_of("f") + 1])
			return ERR;
		else
			return FLOAT;
	}
	return ERR;
}

void ScalarConverter::convertChar() {
	this->_char = static_cast<unsigned char>(this->_input[0]);
	this->_int = static_cast<int>(this->_char);
	this->_double = static_cast<double>(this->_char);
	this->_float = static_cast<float>(this->_char);
}

void ScalarConverter::convertInt() {
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<unsigned char>(this->_int);
	this->_float = static_cast<float>(this->_int);
}

void ScalarConverter::convertDouble() {
	this->_char = static_cast<unsigned char>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
}

void ScalarConverter::convertFloat() {
	this->_float = static_cast<float>(this->_double);
	this->_char = static_cast<unsigned char>(this->_float);
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<double>(this->_float);
}

void ScalarConverter::convert(int inputType) {
	if (inputType == ERR)
		throw ErrorException();
	if (inputType == CHAR)
		this->convertChar();
	if (inputType == INT)
		this->convertInt();
	if (inputType == DOUBLE)
		this->convertDouble();
	if (inputType == FLOAT)
		this->convertFloat();
}

void ScalarConverter::print(int type) {
	// Print char
	std::cout << "Char: ";
	if (type != N_A_N && type != INF && this->_double <= 127) {
		if (isprint(this->_char))
			std::cout << this->_char;
		else
			std::cout << "Non displayable";
	} else {
		std::cout << "Impossible";
	}
	std::cout << std::endl;

	// Print int
	std::cout << "Int: ";
	if (type != N_A_N && type != INF && this->_double <= INT_MAX && this->_double >= INT_MIN) {
		std::cout << this->_int;
	} else {
		std::cout << "Impossible";
	}
	std::cout << std::endl;

	// Print double
	std::cout << "Double: ";
	if (type == N_A_N || type == INF) {
		if (this->_input.find_first_of("+-") == std::string::npos)
			std::cout << "nan";
		else {
			if (this->_input.find_first_of("+") != std::string::npos)
				std::cout << "+inf";
			else
				std::cout << "-inf";
		}
	} else {
		std::cout << std::fixed << this->_double;
	}
	std::cout << std::endl;

	// Print float
	std::cout << "Float: ";
	if (type == N_A_N || type == INF) {
		if (this->_input.find_first_of("+-") == std::string::npos)
			std::cout << "nanf";
		else {
			if (this->_input.find_first_of("+") != std::string::npos)
				std::cout << "+inff";
			else
				std::cout << "-inff";
		}
	} else {
		std::cout << std::fixed << this->_float << "f";
	}
	std::cout << std::endl;
}

const char *ScalarConverter::ErrorException::what() const throw() {
	return "There was some error during a conversion\n";
}

/*
/convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
 */