/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:39 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:40 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#include <string>
#include <map>

class Harl
{
public:
	void			complain( std::string level );
	void			( Harl::*complaints[4] )( void );
	Harl( void );
	~Harl();
private:
	int				getLevel( std::string type ) const;
	std::string		levels[4];
	void			debug( void );
	void			info( void );
	void			warning( void );
	void			error( void );
};
