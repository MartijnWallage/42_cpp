/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:19:48 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/28 16:53:08 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

# include <string>

class	Zombie {
	public:
		void		setName(const std::string& name);
		std::string	getName() const;

		void		announce( void ) const;

		Zombie( std::string name);
		~Zombie( void );
	
	private:
		std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
