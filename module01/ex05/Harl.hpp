#pragma	once
#include <string>
#include <map>

class Harl
{
public:
	void	complain( std::string level );
	Harl( void );
	~Harl();
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	std::map<std::string, void (Harl::*)( void )> complaints;
};
