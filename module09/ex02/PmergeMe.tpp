/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:03 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/30 17:17:05 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// public:

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe()
{
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::~PmergeMe()
{
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe(PmergeMe const & other) : _beforeTime(other._beforeTime), _afterTime(other._afterTime), _input(other._input)
{
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs> & PmergeMe<Container, Pairs>::operator=(PmergeMe const & other)
{
	if (this != &other)
	{
		_input = other._input;
		_beforeTime = other._beforeTime;
		_afterTime = other._afterTime;
	}
	return *this;
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::mergeInsertSort(Container const & input)
{
	_input = input;
	size_t containerSize = _input.size();

	Pairs pairs = _createPairs();
	_recursiveSort(pairs, _sortPairs);

	_sorted.clear();
	_sorted.push_back(pairs.begin()->second);
	for (typename Pairs::iterator it = pairs.begin(); it != pairs.end(); ++it)
		_sorted.push_back(it->first);

	size_t currentPow = 2;
	size_t jacobsthal[2] = {1, 3};
	while (jacobsthal[0] < pairs.size())
	{
		for (size_t j = std::min(jacobsthal[1], pairs.size()); j != jacobsthal[0]; j--)
		{
			if (j - 1 < pairs.size())
			{
				size_t endRange = pow(2, currentPow) - 1;
				endRange = std::min(endRange, _sorted.size() - 1);
				typename Pairs::iterator curr = pairs.begin();
				std::advance(curr, j - 1);
				_binarySearchInsert(_sorted, curr->second, endRange);
			}
		}
		size_t nextJacobsthal = jacobsthal[0] * 2 + jacobsthal[1];
		jacobsthal[0] = jacobsthal[1];
		jacobsthal[1] = nextJacobsthal;
		++currentPow;
	}

	if (containerSize % 2 == 1)
		_binarySearchInsert(_sorted, _input.back(), _sorted.size());
}

template <typename Container, typename Pairs>
void	PmergeMe<Container, Pairs>::startTimer()
{	
	_beforeTime = clock();
}

template <typename Container, typename Pairs>
void	PmergeMe<Container, Pairs>::stopTimer()
{
	_afterTime = clock();
}

template <typename Container, typename Pairs>
double	PmergeMe<Container, Pairs>::getTime() const
{
	return static_cast<double>(_afterTime - _beforeTime) / CLOCKS_PER_SEC * 1e6;
}

template <typename Container, typename Pairs>
Container	PmergeMe<Container, Pairs>::getInput() const
{
	return _input;
}

template <typename Container, typename Pairs>
Container	PmergeMe<Container, Pairs>::getSorted() const
{
	return _sorted;
}

template <typename Container, typename Pairs>
int PmergeMe<Container, Pairs>::getSize() const
{
	return _input.size();
}

// private

template <typename Container, typename Pairs>
void	PmergeMe<Container, Pairs>::_recursiveSort(std::vector<IntPair> & pairs, bool (*compare)(const IntPair, const IntPair))
{
	std::sort(pairs.begin(), pairs.end(), compare);
}

template <typename Container, typename Pairs>
void	PmergeMe<Container, Pairs>::_recursiveSort(std::list<IntPair> & pairs, bool (*compare)(const IntPair, const IntPair))
{
	pairs.sort(compare);
}

template <typename Container, typename Pairs>
bool PmergeMe<Container, Pairs>::_sortPairs(IntPair const pair1, IntPair const pair2)
{
	return pair1.first <= pair2.first;
}

template <typename Container, typename Pairs>
Pairs PmergeMe<Container, Pairs>::_createPairs()
{
	Pairs pairs;
	typename Container::iterator it = _input.begin();
	typename Container::iterator nextIt = it;
	std::advance(nextIt, 1);
	while (it != _input.end() && nextIt != _input.end())
	{
		IntPair pair;
		pair.first = std::max(*it, *nextIt);
		pair.second = std::min(*it, *nextIt);
		pairs.push_back(pair);
		std::advance(it, 2);
		std::advance(nextIt, 2);
	}
	return pairs;
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_binarySearchInsert(Container &chain, int value, int endRange)
{
	typename Container::iterator low = chain.begin();
	typename Container::iterator high = chain.begin();
	std::advance(high, endRange);
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
	chain.insert(low, value);
}
