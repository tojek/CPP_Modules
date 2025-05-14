#pragma once

#include <string>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		// Constructors and destructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		// Getters and setters
		std::string getTarget() const;

		void execute(const Bureaucrat &executor) const;
};