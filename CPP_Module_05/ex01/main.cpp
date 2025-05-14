#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{

	std::cout << "<------ Testing Bureaucrat ------>" << std::endl;

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

	std::cout << "<------ Testing Form ------>" << std::endl;

	try
	{
		Form f1("Form1", 50, 100);
		std::cout << f1 << std::endl;
		f1.beSigned(b3);
		std::cout << f1 << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form f2("Form2", 0, 100);
		std::cout << f2 << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "<------ Additional Tests ------>" << std::endl;

    // Test Bureaucrat increment and decrement at boundaries
    try
    {
        Bureaucrat b4("BoundaryHigh", 1);
        b4.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b5("BoundaryLow", 150);
        b5.decrementGrade();
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test Form signing with insufficient grade
    try
    {
        Bureaucrat b6("Signer", 100);
        Form f3("Form3", 50, 100);
        b6.signForm(f3);
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Test Form signing with sufficient grade
    try
    {
        Bureaucrat b7("Signer", 50);
        Form f4("Form4", 50, 100);
        b7.signForm(f4);
        std::cout << f4 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "<------- Additional tests end ------->" << std::endl;

	std::cout << "<------- tests end ------->" << std::endl;

	return 0;
}