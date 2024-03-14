/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:46:28 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/14 15:40:07 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0.0), _y(0.0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point& orig) : _x(orig._x), _y(orig._y)
{
}

Point& Point::operator=(const Point& other)
{
	this->_x = other._x;
	this->_y = other._y;
	return *this;
}

Point::~Point( void ) {}
