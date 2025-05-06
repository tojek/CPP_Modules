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

	return 0;
}