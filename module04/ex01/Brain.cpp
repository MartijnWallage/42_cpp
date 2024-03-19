/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:44:21 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 17:05:46 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain is created!" << std::endl;
}

Brain::Brain( const Brain& other )
{
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain is cloned!" << std::endl;
}

const Brain&	Brain::operator=( const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain is copied!" << std::endl;
	return *this;
}

Brain::~Brain( void )
{
	std::cout << "Brain is destroyed!" << std::endl;
}