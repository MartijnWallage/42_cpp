#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook {
public:
	PhoneBook();
	PhoneBook(Contact[8]);
	Contact getContact(PhoneBook phonebook, int index) const;
	void setContact(PhoneBook phonebook);
	~PhoneBook();
private:
	Contact	book[8];
};

#endif
