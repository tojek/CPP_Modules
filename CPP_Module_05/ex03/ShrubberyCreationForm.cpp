/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:33:28 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:33:29 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	if (target.empty())
		throw std::invalid_argument("Target cannot be empty");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
	if (copy.target.empty())
		throw std::invalid_argument("Target cannot be empty");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called for ShrubberyCreationForm: " << this->target << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file)
		throw std::runtime_error("Failed to open file");

	file << "Imagine ASCII Art of a shrubbery" << std::endl;
	file.close();
}
