/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:44:21 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/20 18:39:45 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include "Brain.hpp"

Brain::Brain( void )
{
	for (int i = 0; i < 100; i++) {
		std::stringstream	ss;

		ss << i;
		_ideas[i] = "Idea #" + ss.str();
	}
	std::cout << "Brain is created!" << std::endl;
}

Brain::Brain( const Brain& other )
{
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain is copied!" << std::endl;
}

const Brain&	Brain::operator=( const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
		std::cout << "This brain is now the same as the other brain!" << std::endl;
	}
	return *this;
}

Brain::~Brain( void )
{
	std::cout << "Brain is destroyed!" << std::endl;
}