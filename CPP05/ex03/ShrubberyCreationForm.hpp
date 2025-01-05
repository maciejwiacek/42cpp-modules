#pragma once

#include "AForm.hpp"
#include "Colors.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
		// Getters
		std::string const getTarget();
		// Exec
		void execute(const Bureaucrat &b) const;
};