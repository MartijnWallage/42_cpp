/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/29 13:33:40 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <cmath>

template <typename Container = std::vector<int>, typename Pairs = std::vector<std::vector<int>>>
class PmergeMe
{
public:
	PmergeMe(void) {}
	~PmergeMe(void) {}

	Container mergeInsertSort(Container const &unsorted)
	{
		_input = unsorted;
		size_t vecSize = _input.size();

		Pairs pairs;

		// create vector of pairs
		for (size_t i = 0; i + 1 < vecSize; i += 2)
		{
			if (_input[i] < _input[i + 1])
				std::swap(_input[i], _input[i + 1]);
			Container pair;
			pair.push_back(_input[i]);
			pair.push_back(_input[i + 1]);
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

		Container ret;

		// push the second element of the first pair because it is lower than all other elements
		ret.push_back(pairs[0][1]);

		// push all the first elements
		for (size_t i = 0; i < pairs.size(); i++)
			ret.push_back(pairs[i][0]);

		size_t currentPow = 2;
		size_t jacobsthal[2] = {1, 3}; //  1 3 5 11 21
		// insert the second element of each pair, in the Jacobsthal order
		while (jacobsthal[0] < pairs.size())
		{
			for (size_t j = std::min(jacobsthal[1], pairs.size()); j != jacobsthal[0]; j--)
			{
				std::cout << "pairs[" << j - 1 << "] is " << pairs[j - 1][1] << std::endl;
				if (j - 1 < pairs.size())
				{
					size_t endRange = pow(2, currentPow) - 1;
					endRange = std::min(endRange, ret.size() - 1);
					std::cout << "Range is from 0 to " << endRange << std::endl;
					_binarySearchInsert(ret, pairs[j - 1][1], endRange);
				}
			}
			size_t nextJacobsthal = jacobsthal[0] * 2 + jacobsthal[1];
			jacobsthal[0] = jacobsthal[1];
			jacobsthal[1] = nextJacobsthal;
			++currentPow;
		}

		// insert the last element in case it's odd.
		if (vecSize % 2 == 1)
			_binarySearchInsert(ret, _input[vecSize - 1], ret.size() - 1);

		return ret;
	}

private:
	PmergeMe(PmergeMe const &);
	PmergeMe operator=(PmergeMe const &);

	static bool _sortPairs(Container const &pair1, Container const &pair2)
	{
		return pair1[0] <= pair2[0];
	}
	void _binarySearchInsert(Container &chain, int value, int endRange)
	{
				int left = 0;
				int right = endRange;

				while (left <= right)
				{
					int mid = left + (right - left) / 2;
					if (chain[mid] < value)
						left = mid + 1;
					else
						right = mid - 1;
				}
				chain.insert(chain.begin() + left, value);

/* 		typename Container::iterator low = chain.begin();
		typename Container::iterator high = end;
		while (low != high)
		{
			typename Container::iterator mid = low;
			std::advance(mid, std::distance(low, high) / 2);

			if (value < *mid)
			{
				high = mid;
			}
			else
			{
				low = mid;
				++low;
			}
		}

		chain.insert(low, value); */
	}

	Container _input;
};
