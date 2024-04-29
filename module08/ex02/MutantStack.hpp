/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:59:11 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/29 11:12:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void) : std::stack<T>::stack()
	{
		std::cout << "MutantStack constructed" << std::endl;
	}
	MutantStack(MutantStack const &src) : std::stack<T>::stack(src)
	{
		std::cout << "MutantStack copy constructed" << std::endl;
	}
	MutantStack &operator=(MutantStack const &src)
	{
		if (this != &src)
		{
			this->c = src.c;
			std::cout << "MutantStack copy assigned" << std::endl;
		}
		return *this;
	}
	~MutantStack(void)
	{
		std::cout << "MutantStack destructed" << std::endl;
	}

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return std::stack<T>::c.begin(); }
	const_iterator begin() const { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }
	const_iterator end() const { return std::stack<T>::c.end(); }
	reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
	const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
	reverse_iterator rend() { return std::stack<T>::c.rend(); }
	const_reverse_iterator rend() const { return std::stack<T>::c.rend(); }
};
