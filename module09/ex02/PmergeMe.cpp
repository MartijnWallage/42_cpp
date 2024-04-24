/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:03 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 15:22:15 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe(std::list<int> const &unsorted) : _list(unsorted)
{
}

PMergeMe::PMergeMe(std::vector<int> const &unsorted) : _vec(unsorted)
{
}

PMergeMe::PMergeMe(PMergeMe const &src) : _list(src._list), _vec(src._vec)
{
}

PMergeMe PMergeMe::operator=(PMergeMe const &src)
{
	if (this != &src)
	{
		_list = src._list;
		_vec = src._vec;
	}
	return *this;
}

PMergeMe::~PMergeMe() {}

std::list<int> PMergeMe::sort(std::list<int>)
{
}

std::vector<int> PMergeMe::sort(std::vector<int>)
{
}