#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string		phoneNumber;
		std::string		darkestSecret;

	public:
		std::string		firstName;
		std::string		lastName;
		std::string		nickname;

		void			setContact();
		void			displayContactDetail();
		std::string 	truncField(std::string &field);
		std::string 	getNonEmptyInput(std::string prompt);

};



#endif