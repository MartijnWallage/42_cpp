/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 19:07:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <cmath>

class PMergeMe
{
public:
	PMergeMe(void);
	~PMergeMe(void);

	std::list<int> mergeInsertSort(std::list<int> const &);
	std::vector<int> mergeInsertSort(std::vector<int> const &);

private:
	PMergeMe(PMergeMe const &);
	PMergeMe operator=(PMergeMe const &);

	static bool _sortPairs(std::array<int, 2> const & pair1, std::array<int, 2> const & pair2);
	
	void _binarySearchInsert(std::vector<int>& mainChain, int i);
	void _binarySearchInsert(std::list<int>& mainChain, int i);

	static size_t _getIndex(size_t i);

	std::list<int> _numLst;
	std::list<int> _indexLst;
	std::vector<int> _numVec;
	std::vector<int> _indexVec;
};