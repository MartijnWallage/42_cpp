/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:07:59 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/24 18:43:07 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Format: ./PmergeMe <int> <int> ... " << std::endl;
		return 1;
	}
	
	std::vector<int> unsortedVec;
	for (int i = 1; i < argc; i++)
	{
		int nbr = std::atoi(argv[i]);
		unsortedVec.push_back(nbr);
	}
	PMergeMe merge;
	std::vector<int> sortedVec = merge.mergeInsertSort(unsortedVec);

	for (std::vector<int>::iterator it = sortedVec.begin(); it != sortedVec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}