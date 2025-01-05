#pragma once

#include "AForm.hpp"
#include "Colors.hpp"
#include <fstream>
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		// Getters
		std::string const getTarget();
		// Exec
		void execute(const Bureaucrat &b) const;
};