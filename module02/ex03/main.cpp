/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:22:54 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/17 15:35:16 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
    Point a(0.0, 0.0);
    Point b(0.0, 1.0);
    Point c(1.0, 0.0);
    Point point(0.3, 0.3);
    
    bool inside = bsp(a, b, c, point);

    if(inside) {
        std::cout << "The point is inside the triangle." << std::endl;
    } else {
        std::cout << "The point is outside the triangle." << std::endl;
    }
    return 0;
}