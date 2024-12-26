#pragma once

#include "Bureaucrat.hpp"

class Form {
	private:
		std::string const _name;
		bool _isSigned;
		size_t const _gradeToSign;
		size_t const _gradeToExecute;
	public:
		// Initializers
		Form();
		Form(std::string const name, size_t const gradeToSign, size_t const gradeToExecute);
		Form(const Form& copy);
		Form& operator=(const Form& other);
		~Form();

		// Getters
		std::string getName() const;
		bool getIsSigned();
		size_t getGradeToSign() const;
		size_t getGradeToExecute() const;

		// Form Manipulation
		void beSigned(Bureaucrat& b);

	// Exceptions
	class FormAlreadySignedException : public std::exception {
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
	};
};