#pragma once

#include "Colors.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <sstream>

class Bureaucrat;

class AForm {
	protected:
		std::string const _name;
		bool _isSigned;
		size_t const _signGrade;
		size_t const _execGrade;

	public:
		// Initializers
		AForm();
		AForm(const std::string& name, size_t signGrade, size_t execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();
		// Getters
		std::string const getName();
		bool getIsSigned();
		size_t getSignGrade();
		size_t getExecGrade();
		// Manipulation
		void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& b) const;
		// Exceptions
		class GradeTooLowException : public std::exception {
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm& f);