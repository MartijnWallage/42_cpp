/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:35:47 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/06 19:29:09 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "Default ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm with target " << _target
		<< " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & other )
: _target(other._target)
{
	std::cout << "ShrubberyCreationForm with target " << _target
		<< " copy constructed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const & )
{
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm with target " << _target
		<< " destroyed" << std::endl;
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return _target;
}

void ShrubberyCreationForm::beExecuted( Bureaucrat const & ) const
{
	std::ofstream	outfile;

	outfile.open((this->_target + "_shrubbery").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Could not open file " << _target + "_shrubbery" << std::endl;
		return ;
	}

    std::string tree = 
    	"         _______[Root]_______\n"
        "        /                     \\\n"
        "    __[Node1]__           __[Node2]__\n"
        "   /           \\         /           \\\n"
        "[LeafA]     [Node3]   [Node4]     [LeafB]\n"
        "            /    \\     /    \\\n"
        "       [LeafC] [LeafD] [LeafE] [LeafF]\n";

	outfile << tree;
	outfile.close();
}
