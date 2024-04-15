/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:03:33 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/15 16:31:45 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdint.h>
#include <iostream>

struct Data {
	int		n;
	float	f;
};

class Serializer {
	private:
		Serializer( void );
		Serializer( const Serializer & );
		Serializer & operator=( const Serializer &);
		~Serializer( void );
	public:
		static uintptr_t	serialize(Data* ptr );
		static Data*		deserialize(uintptr_t raw);
};
