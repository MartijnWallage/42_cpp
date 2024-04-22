/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:54:15 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 13:56:11 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T, typename Func>
void iter(T *array, size_t len, Func func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(array[i]);
	}
}