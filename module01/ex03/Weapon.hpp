/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:20:57 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/29 14:59:25 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <string>

class Weapon {
public:
						Weapon(const std::string& type);
	const std::string&	getType() const;
	void				setType( std::string type );
						~Weapon( void );
private:
	std::string			_type;
};
