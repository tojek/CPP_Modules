/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:20 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:21 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	if (copy.signGrade < 1 || copy.executeGrade < 1)
		throw GradeTooHighException();
	else if (copy.signGrade > 150 || copy.executeGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Destructor called for Form: " << this->name << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned ?	true : false;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecuteGrade() const
{
	return this->executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form Name: " << form.getName() << ", Is Signed: " << form.getIsSigned() << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
	return os;
}

