/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:03:43 by mwallage          #+#    #+#             */
/*   Updated: 2024/03/24 17:10:30 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_inventory[4];
	public:
		MateriaSource( void );
		MateriaSource( MateriaSource const& other );
		MateriaSource& operator=( MateriaSource const& other );
		~MateriaSource( void );

		void learnMateria( AMateria* );
		AMateria* createMateria( std::string const & type );
};
