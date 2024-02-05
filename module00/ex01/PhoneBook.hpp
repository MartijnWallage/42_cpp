#pragma	once

#include "Contact.hpp"

class	PhoneBook {
public:
	PhoneBook();
	void addContact();
	void searchContact() const;
	void displayContacts() const;
	~PhoneBook();
private:
	Contact		contacts[8];
	int			contact_count;
	std::string	truncateName(const std::string& str) const {
		if (str.length() > 10) {
			return str.substr(0, 9) + ".";
		}
		return str;
	}
};

