/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:48:55 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/17 17:01:50 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <stdexcept>

class NotFoundException : public std::exception {
	const char* what() const throw() {
		return "Int value not found in container";
	}
};

template<typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator	it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
}
