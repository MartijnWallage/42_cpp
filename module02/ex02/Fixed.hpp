/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/24 16:31:43 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	bool	operator>( const Fixed& other ) const;
	bool	operator<( const Fixed& other ) const;
	bool	operator>=( const Fixed& other ) const;
	bool	operator<=( const Fixed& other ) const;
	bool	operator==( const Fixed& other ) const;
	bool	operator!=( const Fixed& other ) const;
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );
	Fixed	operator+( const Fixed& other ) const;
	Fixed	operator-( const Fixed& other ) const;
	Fixed	operator*( const Fixed& other ) const;
	Fixed	operator/( const Fixed& other ) const;

	static const Fixed&	min( const Fixed&, const Fixed& );
	static const Fixed&	max( const Fixed&, const Fixed& );
	static const Fixed&	min( Fixed&, Fixed& );
	static const Fixed&	max( Fixed&, Fixed& );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	friend std::ostream&	operator<<(std::ostream& os, const Fixed& obj);
};

