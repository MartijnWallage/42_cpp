/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:07:59 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/29 15:33:05 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Format: ./PmergeMe <int> <int> ... " << std::endl;
		return 1;
	}

	{
		std::vector<int> unsortedVec;
		std::cout << "Before:\t\t";
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			unsortedVec.push_back(nbr);
			std::cout << std::fixed << unsortedVec.back() << " ";
		}
		std::cout << std::endl;

		PmergeMe merge;
		merge.startTimer();
		std::vector<int> sortedVec = merge.mergeInsertSort(unsortedVec);
		merge.stopTimer();

		std::cout << "After:\t\t";
		for (std::vector<int>::iterator it = sortedVec.begin(); it != sortedVec.end(); ++it)
		{
			std::cout << std::fixed << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Time to process a range of " << sortedVec.size() << " elements with std::vector : ";
		std::cout << std::fixed << std::setprecision(5) << merge.getTime() << " us" << std::endl;
	}

	{
		std::vector<int> unsortedVec;
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			unsortedVec.push_back(nbr);
		}

		PmergeMe merge;
		merge.startTimer();
		std::vector<int> sortedVec = merge.mergeInsertSort(unsortedVec);
		merge.stopTimer();
		std::cout << "Time to process a range of " << sortedVec.size() << " elements with std::vector : ";
		std::cout << std::fixed << std::setprecision(5) << merge.getTime() << " us" << std::endl;
	}

/* 	{
		std::deque<int> unsortedDeq;

		std::cout << "Before:\t\t";
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			unsortedDeq.push_back(nbr);
			std::cout << std::fixed << *(unsortedDeq.end() - 1) << " ";
		}
		std::cout << std::endl;

		clock_t start = clock();
		PmergeMe<std::deque<int>, std::deque<intPair> > mergeDeq;
		std::deque<int> sortedDeq = mergeDeq.mergeInsertSort(unsortedDeq);
		clock_t end = clock();

		std::cout << "After:\t\t";
		for (std::deque<int>::iterator it = sortedDeq.begin(); it != sortedDeq.end(); ++it)
		{
			std::cout << std::fixed << *it << " ";
		}
		std::cout << std::endl;

		double duration = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << sortedDeq.size() << " elements with std::deque : ";
		std::cout << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
	}

	{
		std::deque<int> unsortedDeq;
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			unsortedDeq.push_back(nbr);
		}

		clock_t start = clock();
		PmergeMe<std::deque<int>, std::deque<intPair> > mergeDeq;
		std::deque<int> sortedDeq = mergeDeq.mergeInsertSort(unsortedDeq);
		clock_t end = clock();

		double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << sortedDeq.size() << " elements with std::deque : ";
		std::cout << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
	}
 */

/* 	{
		std::list<int> unsortedDeq;

		std::cout << "Before:\t\t";
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			unsortedDeq.push_back(nbr);
			std::cout << std::fixed << unsortedDeq.back() << " ";
		}
		std::cout << std::endl;

		clock_t start = clock();
		PmergeMe<std::list<int>, std::list<intPair> > mergeDeq;
		std::list<int> sortedDeq = mergeDeq.mergeInsertSort(unsortedDeq);
		clock_t end = clock();

		std::cout << "After:\t\t";
		for (std::list<int>::iterator it = sortedDeq.begin(); it != sortedDeq.end(); ++it)
		{
			std::cout << std::fixed << *it << " ";
		}
		std::cout << std::endl;

		double duration = (double)(end - start) / CLOCKS_PER_SEC * 1e6;
		std::cout << "Time to process a range of " << sortedDeq.size() << " elements with std::deque : ";
		std::cout << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
	} */

	return 0;
}
