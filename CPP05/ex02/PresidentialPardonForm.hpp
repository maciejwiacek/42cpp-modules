#pragma once

#include "AForm.hpp"
#include "Colors.hpp"
#include <fstream>
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		// Getters
		std::string const getTarget();
		// Exec
		void execute(const Bureaucrat &b) const;
};