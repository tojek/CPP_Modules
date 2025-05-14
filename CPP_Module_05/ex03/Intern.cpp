#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Default constructor called for Intern" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy constructor called for Intern" << std::endl;
	*this = copy;
}

Intern::~Intern()
{
	std::cout << "Destructor called for Intern" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Assignment operator called for Intern" << std::endl;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	int i = 0;
	std::string avaibleForms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (i < 3 && formName != avaibleForms[i])
		i++;

	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << formName << std::endl;
		return (new ShrubberyCreationForm(target));
		break;
	case 1:
		std::cout << "Intern creates " << formName << std::endl;
		return (new RobotomyRequestForm(target));
		break;
	case 2:
		std::cout << "Intern creates " << formName << std::endl;
		return (new PresidentialPardonForm(target));
		break;
	default:
		std::cout << "Form is not existing" << std::endl;
		return NULL;
	}
}