#pragma once

class Fixed {
private:
	int					value;
	static const int	frac_bits = 8;
public:
	Fixed( void );
	Fixed( const Fixed& obj );
	Fixed& operator=( const Fixed& other );
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
