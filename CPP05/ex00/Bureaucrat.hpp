#pragma once

#include <iostream>

#define RESET "\033[0m"
#define BLUE  "\033[34m"
#define RED   "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class Bureaucrat {
	private:
		std::string const _name;
		size_t _grade;
	public:
		// Initializers
		Bureaucrat();
		Bureaucrat(std::string const name, size_t grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Getters
		std::string getName() const;
		size_t getGrade() const;

		// Grade Manipulation
		void incrementGrade();
		void decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);