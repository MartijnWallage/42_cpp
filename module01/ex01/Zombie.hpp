#pragma	once

# include <string>

class	Zombie {
	public:
		void		setName(const std::string& nname);
		std::string	getName() const;

		void		announce( void ) const;

		Zombie ( void );
		Zombie( std::string name);
		~Zombie( void );
	
	private:
		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );
