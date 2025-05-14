#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	public:
		// Constructors and destructors
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &copy);
		virtual ~Form();

		// Operators
		Form &operator=(const Form &other);

		// Getters and setters
		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);