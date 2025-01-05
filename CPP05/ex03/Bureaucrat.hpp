#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include "Colors.hpp"

class AForm;

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

		// Form Manipulation
		void signForm(AForm& f);
		void executeForm(AForm const& form);

	// Exceptions
	class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);