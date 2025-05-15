/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:29 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:30 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150) {}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	if (copy.signGrade < 1 || copy.executeGrade < 1)
		throw GradeTooHighException();
	else if (copy.signGrade > 150 || copy.executeGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "Destructor called for AForm: " << this->name << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned ?	true : false;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->executeGrade)
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm Name: " << form.getName() << ", Is Signed: " << form.getIsSigned() << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
	return os;
}

