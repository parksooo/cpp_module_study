/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:09:46 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 18:57:15 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure Default constructor called" << std::endl;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(Cure const &ob)
{
	// std::cout << "Cure Copy constructor called" << std::endl;
	*this = ob;
}

Cure &Cure::operator=(Cure const &ob)
{
	// std::cout << "Cure Assignation constructor called" << std::endl;
	if (this != &ob)
		this->type = ob.type;
	return *this;
}

AMateria *Cure::clone() const
{
	AMateria *p = new Cure();
	return p;
}
