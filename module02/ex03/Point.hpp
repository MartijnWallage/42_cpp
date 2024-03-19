/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:39:36 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 14:58:50 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
private:
	Fixed	_x;
	Fixed	_y;

public:
	Point( void );
	Point(const float x, const float y);
	Point(const Point& orig);
	Point& operator=(Point const& other);
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
