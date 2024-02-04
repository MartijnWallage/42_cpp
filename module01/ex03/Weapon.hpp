
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	public:
		Weapon(const std::string& type) : type(type) {};
		const std::string&	getType() const;
		void				setType( std::string type );
	private:
		std::string	type;
};

#endif