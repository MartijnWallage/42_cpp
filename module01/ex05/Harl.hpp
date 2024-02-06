#pragma	once
#include <string>
#include <map>

class Harl
{
public:
	void			complain( std::string level );
	void			( Harl::*complaints[5] )( void );
	int				getLevel( std::string type ) const;
	Harl( void );
	~Harl();
private:
	std::string		levels[4];
	void			unknown( void );
	void			debug( void );
	void			info( void );
	void			warning( void );
	void			error( void );
};
