/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/30 14:24:43 by mwallage         ###   ########.fr       */
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

struct IntPair
{
	int first;
	int second;
};

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &);
	PmergeMe operator=(PmergeMe const &);

	void				mergeInsertSort(std::vector<int> const & input);
	void				mergeInsertSort(std::list<int> const & input);
	std::vector<int>	getInputVec() const;
	std::list<int>		getInputLst() const;
	std::vector<int>	getSortedVec() const;
	std::list<int>		getSortedLst() const;
	int					getSize() const;
	void				startTimer();
	void				stopTimer();
	double				getTime() const;

private:
	clock_t				_beforeTime;
	clock_t				_afterTime;
	std::vector<int>	_inputVec;
	std::list<int>		_inputLst;
	std::vector<int>	_sortedVec;
	std::list<int>		_sortedLst;

	std::vector<IntPair>	_createPairs(std::vector<int> const & );
	std::list<IntPair>		_createPairs(std::list<int> const & );
	static bool 			_sortPairs(IntPair const pair1, IntPair const pair2);
	static void				_recursiveSort(std::vector<IntPair> & pairs, bool (*compare)(const IntPair, const IntPair));
	static void				_recursiveSort(std::list<IntPair> & pairs, bool (*compare)(const IntPair, const IntPair));
	void 					_binarySearchInsert(std::vector<int> &chain, int value, int endRange);
	void 					_binarySearchInsert(std::list<int> &chain, int value, int endRange);
};
