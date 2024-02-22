/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:22:15 by mwallage         ###   ########.fr       */
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
	float	toFloat( void ) const;
	int		toInt( void ) const;
	Fixed& operator=( const Fixed& other );
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	friend std::ostream&	operator<<(std::ostream& os, const Fixed& obj);
};

