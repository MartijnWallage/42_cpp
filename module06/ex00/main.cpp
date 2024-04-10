/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:46:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/10 16:52:36 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
    ScalarConverter::convert("a");
    ScalarConverter::convert("42");
    ScalarConverter::convert("3.14");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("nan");

    return 0;
}
