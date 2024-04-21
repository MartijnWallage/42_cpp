/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:29:41 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/21 16:29:44 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <ctime>
#include <cstdlib>
#include <list>
#include <algorithm>

int main( )
{
	{
		std::cout << std::endl << "Test from eval sheet" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(3);
		mstack.push(7);
		mstack.push(27);
		mstack.push(21);
		mstack.push(42);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl << "Same test but with list instead of MutantStack" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(3);
		lst.push_back(7);
		lst.push_back(27);
		lst.push_back(21);
		lst.push_back(42);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	{
		std::cout << std::endl << "Some extra tests" << std::endl;
		MutantStack<int> mstack;
		mstack.push(11231235);
		mstack.push(1123127);
		std::cout << "Size of mstack: " << mstack.size() << std::endl;
		MutantStack<int> mstack2(mstack);
		std::cout << "Size of mstack2: " << mstack2.size() << std::endl;
		MutantStack<int> mstack3;
		mstack3 = mstack;
		std::cout << "Size of mstack3: " << mstack3.size() << std::endl;
		std::cout << "Changing mstack..." << std::endl;		
		mstack.pop();
		std::cout << "Top of mstack: " << mstack.top() << std::endl;
		std::cout << "Top of mstack2: " << mstack2.top() << std::endl;
		std::cout << "Top of mstack3: " << mstack3.top() << std::endl;
		std::cout << "Changing mstack 2 and 3..." << std::endl;
		mstack2.push(2);
		mstack3.push(4);
		mstack3.push(5);
		std::cout << "Top of mstack: " << mstack.top() << std::endl;
		std::cout << "Top of mstack2: " <<  mstack2.top() << std::endl;
		std::cout << "Top of mstack3: " <<  mstack3.top() << std::endl;
		MutantStack<int>::reverse_iterator it = mstack3.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack3.rend();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack2);
	}

	return 0;
}
