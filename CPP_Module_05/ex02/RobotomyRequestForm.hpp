/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:47 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:48 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		// Constructors and destructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		// Getters and setters
		std::string getTarget() const;

		void execute(const Bureaucrat &executor) const;
};