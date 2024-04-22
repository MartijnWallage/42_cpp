/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:38:46 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:56:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if (a > b)
		return a;
	return b;
}
