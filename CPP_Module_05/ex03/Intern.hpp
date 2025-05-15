/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:33:08 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:33:09 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
class Bureaucrat;

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string formName, std::string target);
};