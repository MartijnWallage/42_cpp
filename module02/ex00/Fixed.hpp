/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:56 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/17 14:57:27 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {
private:
	int					_value;
	static const int	_fracBits = 8;
public:
	Fixed( void );
	Fixed( const Fixed& obj );
	Fixed& operator=( const Fixed& other );
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
