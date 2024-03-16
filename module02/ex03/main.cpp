/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/16 14:31:40 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
    // Creating vertices of the triangle
    Point a(0.0, 0.0);
    Point b(0.0, 1.0);
    Point c(1.0, 0.0);

    // Point to be checked
    Point point(0.001, 1.0);

    // Checking if the point is inside the triangle
    bool inside = bsp(a, b, c, point);

    // Outputting the result
    if(inside) {
        std::cout << "The point is inside the triangle." << std::endl;
    } else {
        std::cout << "The point is outside the triangle." << std::endl;
    }

    return 0;
}