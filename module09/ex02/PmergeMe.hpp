/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 15:26:13 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>

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

	void _binarySearchInsert(std::vector<int>& mainChain, int i);
	void _binarySearchInsert(std::list<int>& mainChain, int i);
	size_t _getNextIndex(size_t) const;
	
	void _generateIndexVec(std::list<int>);
	void _generateIndexVec(std::vector<int>);
	std::list<int> _numLst;
	std::list<int> _indexLst;
	std::vector<int> _numVec;
	std::vector<int> _indexVec;
};