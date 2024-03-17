/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/17 15:11:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_fracSize = 8;
public:
	Fixed( void );
	Fixed( const Fixed& obj );
	Fixed( const int intValue );
	Fixed( const float floatValue );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	Fixed& operator=( const Fixed& other );
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);
