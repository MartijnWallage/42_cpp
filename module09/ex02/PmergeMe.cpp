/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:03 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/29 12:45:03 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// public:

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> const & input)
{
		_inputVec = input;
		size_t vecSize = _inputVec.size();

		std::vector<intPair> pairs = _createPairs(input);
		std::sort(pairs.begin(), pairs.end(), _sortPairs);

		std::vector<int> ret;
		ret.push_back(pairs.begin()->second);
		for (std::vector<intPair>::iterator it = pairs.begin(); it != pairs.end(); ++it)
			ret.push_back(it->first);

		size_t currentPow = 2;
		size_t jacobsthal[2] = {1, 3};
		while (jacobsthal[0] < pairs.size())
		{
			for (size_t j = std::min(jacobsthal[1], pairs.size()); j != jacobsthal[0]; j--)
			{
				if (j - 1 < pairs.size())
				{
					size_t endRange = pow(2, currentPow) - 1;
					endRange = std::min(endRange, ret.size() - 1);
					std::vector<intPair>::iterator curr = pairs.begin();
					std::advance(curr, j - 1);
					_binarySearchInsert(ret, curr->second, endRange);
				}
			}
			size_t nextJacobsthal = jacobsthal[0] * 2 + jacobsthal[1];
			jacobsthal[0] = jacobsthal[1];
			jacobsthal[1] = nextJacobsthal;
			++currentPow;
		}

		if (vecSize % 2 == 1)
			_binarySearchInsert(ret, _inputVec.back(), ret.size());

		return ret;
	}

void	PmergeMe::startTimer()
{	
	_beforeTime = clock();
}

void	PmergeMe::stopTimer()
{
	_afterTime = clock();
}

double	PmergeMe::getTime() const
{
	return static_cast<double>(_afterTime - _beforeTime) / CLOCKS_PER_SEC * 1e6;
}

// private

bool PmergeMe::_sortPairs(intPair const &pair1, intPair const &pair2)
{
	return pair1.first <= pair2.first;
}

std::vector<intPair> PmergeMe::_createPairs(std::vector<int> const & ) const
{
	std::vector<intPair> pairs;
	std::vector<const int>::iterator it = _inputVec.begin();
	std::vector<const int>::iterator nextIt = it;
	std::advance(nextIt, 1);
	while (it != _inputVec.end() && nextIt != _inputVec.end())
	{
		intPair pair;
		pair.first = std::max(*it, *nextIt);
		pair.second = std::min(*it, *nextIt);
		pairs.push_back(pair);
		std::advance(it, 2);
		std::advance(nextIt, 2);
	}
	return pairs;
}

std::list<intPair> PmergeMe::_createPairs(std::list<int> const & ) const
{
	std::list<intPair> pairs;
	std::list<const int>::iterator it = _inputLst.begin();
	std::list<const int>::iterator nextIt = it;
	std::advance(nextIt, 1);
	while (it != _inputLst.end() && nextIt != _inputLst.end())
	{
		intPair pair;
		pair.first = std::max(*it, *nextIt);
		pair.second = std::min(*it, *nextIt);
		pairs.push_back(pair);
		std::advance(it, 2);
		std::advance(nextIt, 2);
	}
	return pairs;
}


void PmergeMe::_binarySearchInsert(std::vector<int> &chain, int value, int endRange)
{
	std::vector<int>::iterator low = chain.begin();
	std::vector<int>::iterator high = chain.begin() + endRange;
	while (low != high)
	{
		std::vector<int>::iterator mid = low;
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
	chain.insert(low, value);
}

void PmergeMe::_binarySearchInsert(std::list<int> &chain, int value, int endRange)
{
	std::list<int>::iterator low = chain.begin();
	std::list<int>::iterator high = chain.begin();
	std::advance(high, endRange);
	while (low != high)
	{
		std::list<int>::iterator mid = low;
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
	chain.insert(low, value);
}