/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:00:24 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:56:17 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <limits>

void sqr(int n)
{
	std::cout << n * n << std::endl;
}

template <typename T>
void incrementAndPrint(T &x)
{
	x += 1;
	std::cout << x << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, &sqr);

	float floatArr[] = {1.3f, 2.1f, 3.5f, 4.0f, 5.7f, -std::numeric_limits<float>::infinity()};
	iter(floatArr, 6, &incrementAndPrint<float>);
	return 0;
}
