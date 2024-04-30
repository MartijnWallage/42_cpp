/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/30 17:20:11 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <iterator>

struct IntPair
{
	int first;
	int second;
};

template <typename Container, typename Pairs>
class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(PmergeMe const &);
	PmergeMe & operator=(PmergeMe const &);

	void				mergeInsertSort(Container const & input);
	Container			getInput() const;
	Container			getSorted() const;
	int					getSize() const;
	void				startTimer();
	void				stopTimer();
	double				getTime() const;

private:
	clock_t				_beforeTime;
	clock_t				_afterTime;
	Container			_input;
	Container			_sorted;

	Pairs				_createPairs();
	static bool 		_sortPairs(IntPair const pair1, IntPair const pair2);
	static void			_recursiveSort(std::vector<IntPair> & pairs, bool (*compare)(const IntPair, const IntPair));
	static void			_recursiveSort(std::list<IntPair> & pairs, bool (*compare)(const IntPair, const IntPair));
	void 				_binarySearchInsert(Container &chain, int value, int endRange);
};

#include "PmergeMe.tpp"