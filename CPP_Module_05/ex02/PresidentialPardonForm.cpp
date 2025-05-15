/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:41 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:42 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	if (target.empty())
		throw std::invalid_argument("Target cannot be empty");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{
	if (copy.target.empty())
		throw std::invalid_argument("Target cannot be empty");
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called for PresidentialPardonForm: " << this->target << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
