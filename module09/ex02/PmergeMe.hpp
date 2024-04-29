/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/29 15:02:48 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iterator>
#include <type_traits>

struct intPair
{
	int first;
	int second;
};

class PmergeMe
{
public:
	PmergeMe() {}
	~PmergeMe() {}

	std::vector<int>	mergeInsertSort(std::vector<int> const & input);
	std::list<int>		mergeInsertSort(std::list<int> const & input);
	void				startTimer();
	void				stopTimer();
	double				getTime() const;

private:
	clock_t				_beforeTime;
	clock_t				_afterTime;
	std::vector<int>	_inputVec;
	std::list<int>		_inputLst;

	PmergeMe(PmergeMe const &);
	PmergeMe operator=(PmergeMe const &);

	static bool 			_sortPairs(intPair const &pair1, intPair const &pair2);
	std::vector<intPair>	_createPairs(std::vector<int> const & ) const;
	std::list<intPair>		_createPairs(std::list<int> const & ) const;
	void 					_binarySearchInsert(std::vector<int> &chain, int value, int endRange);
	void 					_binarySearchInsert(std::list<int> &chain, int value, int endRange);
};
