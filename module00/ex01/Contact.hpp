#pragma	once

#include <string>

class	Contact {
public:
	Contact();
	void setFirstName(const std::string& fname);
	void setLastName(const std::string& lname);
	void setNickname(const std::string& nname);
	void setPhoneNumber(const std::string& pnumber);
	void setSecret(const std::string& secret);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getSecret() const;
	void displayContact() const;
	~Contact();
private:
	std::string first_name,
				last_name, 
				nickname, 
				secret,
				phone_number;
};
