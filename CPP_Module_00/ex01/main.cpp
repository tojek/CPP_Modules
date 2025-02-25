#include "PhoneBook.hpp"
#include <sstream>

int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while(1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);

		std::cout << cmd << std::endl;
		if (cmd == "ADD")
			phoneBook.addContact();
		else if (cmd == "SEARCH")
		{
			phoneBook.displayContacts();
			phoneBook.searchContact();
		}
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "invalid input" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
