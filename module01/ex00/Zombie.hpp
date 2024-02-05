#pragma	once

# include <string>

class	Zombie {
	public:
		void		setName(const std::string& nname);
		std::string	getName() const;

		void		announce( void ) const;

		Zombie( std::string name);
		~Zombie( void );
	
	private:
		std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
