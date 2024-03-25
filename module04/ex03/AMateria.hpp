#pragma once
#include <string>

class ICharacter;

class AMateria {
	protected:
		std::string const	_type;
		AMateria( void );
		AMateria( AMateria const& other );
		AMateria&	operator=( AMateria const& other );
	public:
		AMateria( std::string const & type );
		virtual ~AMateria( void );

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
