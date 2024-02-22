/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:06 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:20:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

# include <string>

class	Zombie {
	public:
		void		setName(const std::string& nname);
		std::string	getName() const;

		void		announce( void ) const;

		Zombie ( void );
		Zombie( std::string name);
		~Zombie( void );
	
	private:
		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );
