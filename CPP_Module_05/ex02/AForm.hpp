/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:31 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:32 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
	public:
		// Constructors and destructors
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &copy);
		virtual ~AForm();

		// Operators
		AForm &operator=(const AForm &other);

		// Getters and setters
		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);