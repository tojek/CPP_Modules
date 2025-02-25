#include "Contact.hpp"

std::string Contact::getNonEmptyInput(std::string prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			break;
		std::cout << "Input cannot be empty." << std::endl;
	}
	return input;
}

void	Contact::setContact()
{
	firstName = getNonEmptyInput("Enter First Name: ");
	lastName = getNonEmptyInput("Enter Last Name: ");
	nickname = getNonEmptyInput("Enter Nickname: ");
	phoneNumber = getNonEmptyInput("Enter Phone Number: ");
	darkestSecret = getNonEmptyInput("Enter Darkest Secret: ");
}

std::string	Contact::truncField(std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	Contact::displayContactDetail()
{
	std::cout << "| First Name: " 		<< firstName << std::endl;
    std::cout << "| Last Name: " 		<< lastName << std::endl;
    std::cout << "| Nickname: " 		<< nickname << std::endl;
    std::cout << "| Phone Number: " 	<< phoneNumber << std::endl;
    std::cout << "| Darkest Secret: " 	<< darkestSecret << std::endl;
}
