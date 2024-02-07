#pragma once

class Fixed {
private:
	int	number;
	static const int	frac_bits = 8;
public:
	Fixed();
	Fixed(int orig);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
