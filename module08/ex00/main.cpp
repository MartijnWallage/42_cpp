/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:56:49 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/17 17:02:18 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    try {
        // Test with std::vector
        std::vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);
        std::vector<int>::iterator vecResult = easyfind(vec, 3);
        std::cout << "Found in vector: " << *vecResult << std::endl;

        // Test with std::list
        std::list<int> lst;
		for (int i = 0; i < 10; i++)
			lst.push_back(i);
        std::list<int>::iterator listResult = easyfind(lst, 4);
        std::cout << "Found in list: " << *listResult << std::endl;

        // Test with no occurrence
        std::vector<int>::iterator failTest = easyfind(vec, 99);  // This should throw
        std::cout << "Found in vector: " << *failTest << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}