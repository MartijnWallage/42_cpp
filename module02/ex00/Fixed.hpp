/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:56 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:58 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
