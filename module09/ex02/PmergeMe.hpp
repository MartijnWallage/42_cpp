/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:08:07 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 15:57:28 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>

class PMergeMe
{
public:
	PMergeMe(std::list<int> const &);
	PMergeMe(std::vector<int> const &);
	~PMergeMe();

	std::list<int> sort(std::list<int>);
	std::vector<int> sort(std::vector<int>);

private:
	PMergeMe(PMergeMe const &);
	PMergeMe operator=(PMergeMe const &);

	void _binarySearchInsert(std::vector<int>& mainChain, int i);
	void _binarySearchInsert(std::list<int>& mainChain, int i);
	int _getNextJacobsthal(int);
	std::list<int> _list;
	std::vector<int> _vec;
};