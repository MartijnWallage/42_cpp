/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:49:17 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:58:01 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int choice = std::rand() % 3;

	switch (choice)
	{
	case 0:
		std::cout << "Instantiating A" << std::endl;
		return new A();
	case 1:
		std::cout << "Instantiating B" << std::endl;
		return new B();
	case 2:
		std::cout << "Instantiating C" << std::endl;
		return new C();
	default:
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Object is of type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Object is of type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Object is of type C" << std::endl;
	else
		std::cout << "Object is of unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Reference is of type A" << std::endl;
		return;
	}
	catch (std::exception &bc)
	{
		std::cout << "Reference is not of type A" << std::endl;
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Reference is of type B" << std::endl;
		return;
	}
	catch (std::exception &bc)
	{
		std::cout << "Reference is not of type B" << std::endl;
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Reference is of type C" << std::endl;
		return;
	}
	catch (std::exception &bc)
	{
		std::cout << "Reference is not of type C" << std::endl;
	}

	std::cout << "Reference is of unknown type" << std::endl;
}

int main(void)
{
	Base *base;

	base = generate();
	std::cout << base << std::endl;

	identify(base);
	identify(*base);
	delete base;
	return 0;
}