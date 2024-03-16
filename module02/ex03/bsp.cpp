/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:56:00 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/16 14:30:32 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static Fixed    area_size(Point const a, Point const b, Point const c)
{
    Fixed   result;

    result = a.getX() * (b.getY() - c.getY());
    result = result + b.getX() * (c.getY() - a.getY());
    result = result + c.getX() * (a.getY() - b.getY());
    result = result.abs() / 2;
    return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed   total_size, size1, size2, size3;

    total_size = area_size(a, b, c);
    size1 = area_size(point, a, b);
    size2 = area_size(point, b, c);
    size3 = area_size(point, a, c);
    std::cout << "a: " << a.getX() << "," << a.getY() << " b: " << b.getX() << "," << b.getY() << " c: " << c.getX() << "," << c.getY() << std::endl; 
    std::cout << "Total size: " << total_size << std::endl;
    std::cout << "Size1: " << size1 << std::endl;
    std::cout << "Size2: " << size2 << std::endl;
    std::cout << "Size3: " << size3 << std::endl;
    std::cout << "Size1 + size2 + size3: " << size1 + size2 + size3 << std::endl;
    return ((total_size - (size1 + size2 + size3)).abs() < Fixed(0.01f));
}
