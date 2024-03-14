=-098765 +
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:39:36 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/14 14:40:25 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
private:
	const Fixed	_x;
	const Fixed _y;

public:
	Point( void );
	Point(const float x, const float y);
	Point(const Point& orig);
	Point& operator=(const Point& other);
	~Point( void );
};
