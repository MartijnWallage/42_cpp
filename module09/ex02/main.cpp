/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:07:59 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/30 17:17:26 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

template <typename Container, typename Pairs>
void printMerge(PmergeMe<Container, Pairs> & merge)
{
	Container	before = merge.getInput();

	std::cout << "Before:\t\t";
	for (typename Container::iterator it = before.begin(); it != before.end(); ++it)
	{
		std::cout << std::fixed << *it << " ";
	}
	std::cout << std::endl;

	Container	after = merge.getSorted();
	std::cout << "After:\t\t";
	for (typename Container::iterator it = after.begin(); it != after.end(); ++it)
	{
		std::cout << std::fixed << *it << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Format: ./PmergeMe <int> <int> ... " << std::endl;
		return 1;
	}

	{
		std::vector<int> unsortedVec;
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			if (nbr < 0)
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
			unsortedVec.push_back(nbr);
		}

		PmergeMe<std::vector<int>, std::vector<IntPair> > merge;
		merge.startTimer();
		merge.mergeInsertSort(unsortedVec);
		merge.stopTimer();
		printMerge(merge);
		std::cout << "Time to process a range of " << merge.getSize() << " elements with std::vector : ";
		std::cout << std::fixed << std::setprecision(1) << merge.getTime() << " us" << std::endl;
	}

	{
		std::list<int> unsortedLst;
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			if (nbr < 0)
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
			unsortedLst.push_back(nbr);
		}

		PmergeMe<std::list<int>, std::list<IntPair> > merge;
		merge.startTimer();
		merge.mergeInsertSort(unsortedLst);
		merge.stopTimer();
		std::cout << "Time to process a range of " << merge.getSize() << " elements with std::list : ";
		std::cout << std::fixed << std::setprecision(1) << merge.getTime() << " us" << std::endl;
	}
	return 0;
}
