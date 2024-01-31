#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	secret = "";
}

void Contact::setFirstName(const std::string& fname) {
	first_name = fname;
}

void Contact::setLastName(const std::string& lname) {
	last_name = lname;
}

void Contact::setNickname(const std::string& nname) {
	nickname = nname;
}

void Contact::setPhoneNumber(const std::string& pnumber) {
	phone_number = pnumber;
}

void Contact::setSecret(const std::string& dsecret) {
	secret = dsecret;
}

std::string Contact::getFirstName() const {
	return first_name;
}
	
std::string Contact::getLastName() const {
	return last_name;
}
	
std::string Contact::getNickname() const {
	return nickname;
}

std::string Contact::getPhoneNumber() const {
	return phone_number;
}
	
std::string Contact::getSecret() const {
	return secret;
}

void Contact::displayContact() const {
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}

Contact::~Contact() {}