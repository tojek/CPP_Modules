/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:32:12 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:32:13 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat b1("John", 50);
		Bureaucrat b2("Jane", 200);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	Bureaucrat b3("Jack", 42);

	b3.incrementGrade();
	std::cout << b3 << std::endl;
	b3.decrementGrade();
	std::cout << b3 << std::endl;


	return 0;
}