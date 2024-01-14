#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class	Contact {
public:
	Contact();
	Contact(string, string, string, string, int);
	Contact getContact() const;
	void setContact(string, string, string, string, int);
	void displayContact(Contact) const;
	~Contact();
private:
	string	firstname,
			lastname, 
			nickname, 
			secret;
	int		phonenumber;
};

#endif