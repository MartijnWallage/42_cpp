/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:21 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 16:55:49 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#include <string>
#include <map>

class Harl
{
public:
	void			complain( std::string level );
	void			( Harl::*complaints[5] )( void );
	Harl( void );
	~Harl();
private:
	int				_getLevel( std::string type ) const;
	std::string		_levels[4];
	void			_unknown( void );
	void			_debug( void );
	void			_info( void );
	void			_warning( void );
	void			_error( void );
};
