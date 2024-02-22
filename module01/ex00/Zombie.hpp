/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:19:48 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:19:49 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

# include <string>

class	Zombie {
	public:
		void		setName(const std::string& nname);
		std::string	getName() const;

		void		announce( void ) const;

		Zombie( std::string name);
		~Zombie( void );
	
	private:
		std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
