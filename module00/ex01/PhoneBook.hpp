/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:18:23 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/24 08:41:21 by mwallage         ###   ########.fr       */
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
	Contact		contacts[8];
	int			contact_count;
	std::string	truncateName(const std::string& str) const;
};
