/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:42:05 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:55:30 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t N) : _capacity(N)
{
	std::cout << "Span with capacity " << _capacity << " constructed" << std::endl;
}

Span::Span(Span const &src) : _capacity(src._capacity), _numbers(src._numbers)
{
	std::cout << "Span with capacity " << _capacity << " copy constructed" << std::endl;
}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		_capacity = src._capacity;
		_numbers = src._numbers;
		std::cout << "Span copy assigned" << std::endl;
	}
	return *this;
}

Span::~Span(void)
{
	std::cout << "Span destructed" << std::endl;
}

void Span::addNumber(int nbr)
{
	if (_numbers.size() == _capacity)
		throw std::length_error("Cannot add number because span is full.");
	std::cout << "Adding " << nbr << "..." << std::endl;
	_numbers.push_back(nbr);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
		addNumber(*begin++);
}

unsigned int Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
	{
		throw std::logic_error("No span can be found because size of vector is less than 2.");
	}

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minSpan = sortedNumbers[1] - sortedNumbers[0];

	for (size_t i = 1; i < sortedNumbers.size() - 1; i++)
	{
		int currentSpan = sortedNumbers[i + 1] - sortedNumbers[i];
		minSpan = std::min(minSpan, currentSpan);
	}

	return minSpan;
}

unsigned int Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
	{
		throw std::logic_error("No span can be found because size of vector is less than 2.");
	}

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return (sortedNumbers.back() - sortedNumbers.front());
}
