/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:43:29 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/26 15:04:03 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &ob)
{
	// std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = ob.slot[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &ob)
{
	// std::cout << "MateriaSource Assigantion constructor called" << std::endl;
	if (this != &ob)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->slot[i])
				delete this->slot[i];
			this->slot[i] = ob.slot[i];
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->slot[i])
			delete this->slot[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (!this->slot[i])
		{
			this->slot[i] = m;
			return ;
		}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->slot[i] && !this->slot[i]->getType().compare(type))
			return this->slot[i]->clone();
	}
	return 0;
}
