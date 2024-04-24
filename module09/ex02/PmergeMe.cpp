/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:03 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 15:25:19 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe( void )
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

std::array<int, 2> PMergeMe::_sortPairs(std::array<int, 2> pair1, std::array<int, 2> pair2)
{
	return pair1[0] > pair2[1] ? pair1: pair2;
}

std::list<int> PMergeMe::mergeInsertSort(std::list<int> const & unsorted)
{
	_numLst = unsorted;
}


void PMergeMe::_binarySearchInsert(std::vector<int>& mainChain, int i)
{
	
}

std::vector<int> PMergeMe::mergeInsertSort(std::vector<int> const & unsorted)
{
	_numVec = unsorted;
	size_t vecSize = _numVec.size();
	
	std::vector<std::array<int, 2>> pairs;

	// create vector of pairs
	for (size_t i = 0; i < vecSize - 2; i++)
	{
		if (_numVec[i] < _numVec[i + 1])
			std::swap(_numVec[i], _numVec[i + 1]);
		std::array<int, 2> pair = {_numVec[i], _numVec[i + 1]};
		pairs.push_back(pair);
	}
	
	// sort vector of pairs according to the order of the first element in each pair
	std::sort(pairs.begin(), pairs.end(), &_sortPairs);

	std::vector<int> ret;

	// push the second element of the first pair because it is lower than all other elements
	ret.push_back(pairs[0][1]);

	// push the first element of each pair
	for (size_t i = 0; i < pairs.size(); i++)
		ret.push_back(pairs[i][0]);

	// insert the second element of each pair, in the Jacobsthal order
	for (size_t i = 0; i < vecSize; i++)
	{
		size_t j = _indexVec[i];
		_binarySearchInsert(ret, pairs[j][1]);
	}

	// insert the last element in case it's odd. Not sure if this follows the algorithm.
	if (vecSize % 2 == 1)
		_binarySearchInsert(ret, _numVec[vecSize - 1]);

	return ret;
}
