#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class PhoneBook
{
	private:
		Contact		contacts[8];
		int			index;
	public:
		PhoneBook();
		~PhoneBook();
		void		addContact();
		void		displayContacts();
		void		searchContactID(int id);
		void		searchContact();
};

#endif