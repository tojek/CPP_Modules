/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:17 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:18 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	if (copy.grade < 1)
		throw GradeTooHighException();
	else if (copy.grade > 150)
		throw GradeTooLowException();
	this->grade = copy.grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called for Bureaucrat: " << this->name << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}