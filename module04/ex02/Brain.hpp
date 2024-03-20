/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:44:18 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/19 17:05:51 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain {
	protected:
		std::string	_ideas[100];
	public:
		Brain( void );
		Brain( const Brain& other );
		const Brain&	operator=( const Brain& other);
		~Brain( void );
};
