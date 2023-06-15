/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:20:43 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 18:57:04 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : name(name)
{
	// std::cout << "Character " << name << " constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::Character(Character const &ob)
{
	// std::cout << "Character Copy constructor called" << std::endl;
	*this = ob;
}

Character &Character::operator=(Character const &ob)
{
	// std::cout << "Character Assignation constructor called" << std::endl;
	
	if (this != &ob)
	{
		this->name = ob.name;
		for (int i = 0; i < 4; i++)
			this->inventory[i] = ob.inventory[i];
	}
	return *this;
}

Character::~Character()
{
	// std::cout << "Character descontructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i < 4; i++)
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
}

void Character::unequip(int idx)
{
	for (int i = 0; i < 4; i++)
		if (i == idx && this->inventory[i])
			this->inventory[i] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}
