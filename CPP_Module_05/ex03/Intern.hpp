#pragma once
#include "AForm.hpp"
class Bureaucrat;

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string formName, std::string target);
};