/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:24:02 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 19:14:30 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("unknown")
{
	// std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	// std::cout << "AMateria " << type << " constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &ob)
{
	// std::cout << "AMateria destructor called" << std::endl;
	*this = ob;
}

AMateria &AMateria::operator=(AMateria const &ob)
{
	// std::cout << "AMateria Assignation constructor called" << std::endl;
	if (this != &ob)
		this->type = ob.type;
	return *this;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria desconstructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	if (!this->getType().compare("ice"))
		std::cout << "* shoots an ice bolt at "<< target.getName() << " *"<< std::endl;
	else if (!this->getType().compare("cure"))
		std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
