#pragma once
#include <iostream>

class Fixed {
private:
	int					value;
	static const int	fracSize = 8;
public:
	Fixed( void );
	Fixed( const Fixed& obj );
	Fixed( const int intValue );
	Fixed( const float floatValue );
	~Fixed( void );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed&	operator=( const Fixed& other );
	int		operator>( const Fixed& other ) const;
	int		operator<( const Fixed& other ) const;
	int		operator>=( const Fixed& other ) const;
	int		operator<=( const Fixed& other ) const;
	int		operator==( const Fixed& other ) const;
	int		operator!=( const Fixed& other ) const;
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );
	Fixed	operator+( const Fixed& other ) const;
	Fixed	operator-( const Fixed& other ) const;
	Fixed	operator*( const Fixed& other ) const;
	Fixed	operator/( const Fixed& other ) const;

	static Fixed&		min(Fixed&, Fixed&);
	static const Fixed&	min(const Fixed&, const Fixed&);
	static const Fixed&	min(const Fixed&, Fixed&);
	static const Fixed&	min(Fixed&, const Fixed&);
	static Fixed&		max(Fixed&, Fixed&);
	static const Fixed&	max(const Fixed&, const Fixed&);
	static const Fixed&	max(const Fixed&, Fixed&);
	static const Fixed&	max(Fixed&, const Fixed&);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	friend std::ostream&	operator<<(std::ostream& os, const Fixed& obj);
};
