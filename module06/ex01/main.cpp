/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:25:50 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/15 16:36:12 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data		someData;
	Data*		dataPtr;
	uintptr_t	address;

	address = Serializer::serialize(&someData);
	dataPtr = Serializer::deserialize(address);

	if (address == reinterpret_cast<uintptr_t>(dataPtr))
		std::cout << "Address has value " << reinterpret_cast<void*>(address)
			<< " and dataPtr has value " << dataPtr
			<< ", so they have the same value." << std::endl;
	else
		std::cout << "Address has value " << reinterpret_cast<void*>(address)
			<< " and dataPtr has value " << dataPtr
			<< "so they do not have the same value." << std::endl;

}
