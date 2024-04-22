/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:30:15 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:55:35 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span
{
private:
	size_t _capacity;
	std::vector<int> _numbers;

public:
	Span(size_t N);
	Span(Span const &);
	Span &operator=(Span const &);
	~Span(void);

	void addNumber(int nbr);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
};
