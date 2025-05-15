/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:50 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:51 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		// Constructors and destructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		// Getters and setters
		std::string getTarget() const;

		void execute(const Bureaucrat &executor) const;
};