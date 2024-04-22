/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:25:13 by mwallage          #+#    #+#             */
/*   Updated: 2024/04/22 14:00:16 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

	PresidentialPardonForm(void);
	void beExecuted(Bureaucrat const &bureaucrat) const;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &);
	~PresidentialPardonForm(void);

	std::string getTarget(void) const;
};
