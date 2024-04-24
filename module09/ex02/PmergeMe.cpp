/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:03 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 20:25:34 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe( void ) {}

PMergeMe::~PMergeMe() {}


std::list<int> PMergeMe::mergeInsertSort(std::list<int> const & unsorted)
{
	_numLst = unsorted;
	return _numLst;
}

size_t	jacobsthal(size_t n)
{
	return (std::pow(2, n) - std::pow(-1, n)) / 3.0;
}

bool isJacobsthal(size_t n)
{
	size_t jacobsNumeral = std::pow(2, n) - std::pow(-1, n);
	return jacobsNumeral % 3 == 0;
}

size_t PMergeMe::_getIndex(size_t i)
{
	if (isJacobsthal(i))
		return jacobsthal(i + 1) - 1;
	return i - 1;
}

void PMergeMe::_binarySearchInsert(std::vector<int>& mainChain, int b)
{
    int left = 0;
    int right = mainChain.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mainChain[mid] < b) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    mainChain.insert(mainChain.begin() + left, b);
}

bool PMergeMe::_sortPairs(std::array<int, 2> const & pair1, std::array<int, 2> const & pair2)
{
	return pair1[0] <= pair2[0];
}

std::vector<int> PMergeMe::mergeInsertSort(std::vector<int> const & unsorted)
{
	_numVec = unsorted;
	size_t vecSize = _numVec.size();
	
	std::vector<std::array<int, 2> > pairs;


	// create vector of pairs
	for (size_t i = 0; i < vecSize / 2; i += 2)
	{
		if (_numVec[i] > _numVec[i + 1])
			std::swap(_numVec[i], _numVec[i + 1]);
		std::array<int, 2> pair = {_numVec[i], _numVec[i + 1]};
		pairs.push_back(pair);
	}
	
	// sort vector of pairs according to the order of the first element in each pair
	std::sort(pairs.begin(), pairs.end(), _sortPairs);

	std::vector<int> ret;

	// push the second element of the first pair because it is lower than all other elements
	ret.push_back(pairs[0][1]);

	size_t lastJacobsthal = 1;
	// insert the second element of each pair, in the Jacobsthal order
	for (size_t i = 1; i < pairs.size(); i++)
	{
		size_t j = _getIndex(i);
		if (isJacobsthal(i))
		{
			for (--lastJacobsthal; lastJacobsthal < j; lastJacobsthal++)
				ret.push_back(pairs[lastJacobsthal][0])
		}
		_binarySearchInsert(ret, pairs[j][1]);
	}

	// insert the last element in case it's odd.
	if (vecSize % 2 == 1)
		_binarySearchInsert(ret, _numVec[vecSize - 1]);

	return ret;
}
