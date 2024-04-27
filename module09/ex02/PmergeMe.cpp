/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:03 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/27 23:19:52 by mwallage         ###   ########.fr       */
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
	// incorrect. Wrong answer for n = 2;
	// closed form may work for jacobsthal numbers but not to determine whether a number is jacobsthal
	size_t jacobsNumeral = std::pow(2, n) - std::pow(-1, n);
	return jacobsNumeral % 3 == 0;
}

size_t PMergeMe::_getIndex(size_t i)
{
	if (isJacobsthal(i))
	{
		std::cout << i << " is a jacobsthal number" << std::endl;
		return jacobsthal(i + 1) - 1;
	}
	std::cout << i << " is not a jacobsthal number" << std::endl;
	return i - 1;
}

void PMergeMe::_binarySearchInsert(int value, std::vector<int>& chain, size_t end)
{
    int left = 0;
    int right = end;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (chain[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    chain.insert(chain.begin() + left, value);
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
	for (size_t i = 0; i < vecSize; i += 2)
	{
		if (_numVec[i] < _numVec[i + 1])
			std::swap(_numVec[i], _numVec[i + 1]);
		std::array<int, 2> pair = {_numVec[i], _numVec[i + 1]};
		pairs.push_back(pair);
	}
	
	std::cout << "Unsorted pairs:" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i][0] << "," << pairs[i][1] << std::endl;
	std::cout << std::endl;

	// sort vector of pairs according to the order of the first element in each pair
	std::sort(pairs.begin(), pairs.end(), _sortPairs);

	std::cout << "Sorted pairs:" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << pairs[i][0] << "," << pairs[i][1] << std::endl;
	std::cout << std::endl;

	std::vector<int> ret;

	// push the second element of the first pair because it is lower than all other elements
	ret.push_back(pairs[0][1]);
	
	// push all the first elements
	for (size_t i = 0; i < pairs.size(); i++)
		ret.push_back(pairs[i][0]);
		
/* 	std::cout << "Ret after pushing first elements:" << std::endl;
	for (size_t i = 0; i < ret.size(); i++)
		std::cout << ret[i] << std::endl;
	std::cout << std::endl; */

	size_t currentPow = 2;
	size_t jacobsthal[2] = {1, 3}; //  1 3 5 11 21
	// insert the second element of each pair, in the Jacobsthal order
	while (jacobsthal[0] < pairs.size())
	{
		for (size_t j = std::min(jacobsthal[1], pairs.size()); j != jacobsthal[0]; j--)
		{
			std::cout << "pairs[" << j - 1 << "] is " << pairs[j - 1][1] << std::endl;
			if (j - 1 < pairs.size()) {
				size_t endRange = pow(2, currentPow) - 1;
				endRange = std::min(endRange, ret.size() - 1);
				std::cout << "Range is from 0 to " << endRange << std::endl;
				_binarySearchInsert(pairs[j - 1][1], ret, endRange);
			}
		}
		size_t nextJacobsthal = jacobsthal[0] * 2 + jacobsthal[1];
		jacobsthal[0] = jacobsthal[1];
		jacobsthal[1] = nextJacobsthal;
		++currentPow;
	}

	// insert the last element in case it's odd.
//	if (vecSize % 2 == 1)
//		_binarySearchInsert(_numVec[vecSize - 1], ret, pow(2, currentPow) - 1);

	return ret;
}
