/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:03:37 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/25 15:56:29 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal	*farm[100];

	for (int i = 0; i < 50; i++) {
		farm[i] = new Cat;
	}
	for (int i = 50; i < 100; i++) {
		farm[i] = new Dog;
	}
	for (int i = 0; i < 100; i++) {
		farm[i]->makeSound();
		delete farm[i];
	}
	Dog	testDog;
	Dog cloneDog(testDog);
	Dog copyDog = testDog;
	copyDog = cloneDog;
	
	Brain* testBrain = copyDog.getBrain();
	*testBrain = *cloneDog.getBrain();
	*testBrain = *testBrain;

	Cat	testCat;
	Cat cloneCat(testCat);
	Cat copyCat = testCat;
	copyCat = cloneCat;
	
	return 0;
}