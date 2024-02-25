/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:23 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/25 17:06:46 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Contact		_contacts[8];
	int			_contact_count;
	int			_index;
	std::string	_truncateName(const std::string& str) const;
	std::string	_getInput(const std::string& message) const;
};
