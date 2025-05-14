#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	if (target.empty())
		throw std::invalid_argument("Target cannot be empty");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
	if (copy.target.empty())
		throw std::invalid_argument("Target cannot be empty");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called for RobotomyRequestForm: " << this->target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);
	int random = std::rand() % 2;
	std::cout << "Bzzzzzzzzzzz" << std::endl;
	if (random < 0.5)
	{
		std::cout << "Robotomy on " << this->target << " has been successful!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy on " << this->target << " has failed!" << std::endl;
	}
}