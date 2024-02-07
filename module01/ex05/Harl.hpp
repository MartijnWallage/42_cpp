#pragma	once
#include <string>
#include <map>

class Harl
{
public:
	void			complain( std::string level );
	void			( Harl::*complaints[5] )( void );
	Harl( void );
	~Harl();
private:
	int				getLevel( std::string type ) const;
	std::string		levels[4];
	void			unknown( void );
	void			debug( void );
	void			info( void );
	void			warning( void );
	void			error( void );
};
