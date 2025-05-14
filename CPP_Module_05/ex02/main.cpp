#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "<------- tests start ------->" << std::endl;

    try
    {
        Bureaucrat john("John", 1);
        Bureaucrat jane("Jane", 50);
        Bureaucrat jack("Jack", 150);

        PresidentialPardonForm presidentialForm("Alice");
        RobotomyRequestForm robotomyForm("Bob");
        ShrubberyCreationForm shrubberyForm("Garden");

        // Test signing and executing PresidentialPardonForm
        john.signForm(presidentialForm);
        john.executeForm(presidentialForm);

        // Test signing and executing RobotomyRequestForm
        jane.signForm(robotomyForm);
        jane.executeForm(robotomyForm);

        // Test signing and executing ShrubberyCreationForm
        jack.signForm(shrubberyForm);
        jack.executeForm(shrubberyForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	std::cout << "<---- rank tests ----->" << std::endl;
    try
    {
        Bureaucrat lowRank("LowRank", 150);
        Bureaucrat midRank("MidRank", 100);
        Bureaucrat highRank("HighRank", 1);

        ShrubberyCreationForm shrubbery("Park");
        RobotomyRequestForm robotomy("Robot");
        PresidentialPardonForm pardon("Criminal");

        // Test: LowRank trying to sign and execute forms
        try
        {
            lowRank.signForm(shrubbery);
            lowRank.executeForm(shrubbery);
        }
        catch (const std::exception &e)
        {
            std::cerr << "LowRank error: " << e.what() << std::endl;
        }

        // Test: MidRank signing but failing to execute high-grade-required form
        try
        {
            midRank.signForm(robotomy);
            midRank.executeForm(robotomy);
        }
        catch (const std::exception &e)
        {
            std::cerr << "MidRank error: " << e.what() << std::endl;
        }

        // Test: HighRank successfully signing and executing all forms
        try
        {
            highRank.signForm(pardon);
            highRank.executeForm(pardon);
        }
        catch (const std::exception &e)
        {
            std::cerr << "HighRank error: " << e.what() << std::endl;
        }

        // Test: Attempting to execute an unsigned form
        try
        {
            highRank.executeForm(shrubbery);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Unsigned form error: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "General error: " << e.what() << std::endl;
    }

    std::cout << "<------- tests end ------->" << std::endl;

    return 0;
}