/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:33:11 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/05/15 13:33:12 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "<------- tests start ------->" << std::endl;

    Intern intern;
    Bureaucrat bureaucrat("John", 1);

    // Test valid form creation
    AForm *robotomyForm = intern.makeForm("RobotomyRequestForm", "Target1");
    AForm *pardonForm = intern.makeForm("PresidentialPardonForm", "Target2");
    AForm *shrubberyForm = intern.makeForm("ShrubberyCreationForm", "Target3");

    // Test invalid form creation
    AForm *invalidForm = intern.makeForm("invalid form", "Target4");

    // Test signing and executing valid forms
    if (robotomyForm) {
        bureaucrat.signForm(*robotomyForm);
        bureaucrat.executeForm(*robotomyForm);
        delete robotomyForm;
    }

    if (pardonForm) {
        bureaucrat.signForm(*pardonForm);
        bureaucrat.executeForm(*pardonForm);
        delete pardonForm;
    }

    if (shrubberyForm) {
        bureaucrat.signForm(*shrubberyForm);
        bureaucrat.executeForm(*shrubberyForm);
        delete shrubberyForm;
    }

    // Clean up invalid form
    if (invalidForm) {
        delete invalidForm;
    }

    std::cout << "<------- tests end ------->" << std::endl;

    return 0;
}