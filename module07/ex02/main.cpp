/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:42:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:56:33 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < arr.size(); ++i)
		{
			arr[i] = i * 10;
		}

		Array<int> copyConstructArr(arr);

		std::cout << "Changing constructed copy value: " << (copyConstructArr[0] = 999) << std::endl;
		std::cout << "Original value: " << arr[0] << std::endl;
		std::cout << "Changing original value: " << (arr[0] = 888) << std::endl;
		std::cout << "Assigned constructed copy value: " << copyConstructArr[0] << std::endl;
		std::cout << "Setting original value back to: " << (arr[0] = 0) << std::endl;
		Array<int> copyAssignArr;
		copyAssignArr = arr;

		std::cout << "Changing assigned copy value: " << (copyAssignArr[0] = 999) << std::endl;
		std::cout << "Original value: " << arr[0] << std::endl;
		std::cout << "Changing original value: " << (arr[0] = 888) << std::endl;
		std::cout << "Assigned copy value: " << copyAssignArr[0] << std::endl;

		//  std::cout << "Accessing out of bounds: " << arr[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}