/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:10 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:11 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	// Constructors and destructors
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	// Operators
	Bureaucrat &operator=(const Bureaucrat &other);

	// Getters and setters
	std::string getName() const;
	int getGrade() const;

	// Functions
	void incrementGrade();
	void decrementGrade();

	// Exceptions
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

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);