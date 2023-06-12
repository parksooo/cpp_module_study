/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:57:14 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/11 15:18:19 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <sstream>

ClapTrap::ClapTrap()
{
	this->name = "default";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;

	std::cout << "ClapTrap " << name << " constructor called" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap &ob)
{
	this->name = ob.name;
	this->hitPoint = ob.hitPoint;
	this->energyPoint = ob.energyPoint;
	this->attackDamage = ob.attackDamage;

	std::cout << "ClapTrap " << this->name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ob)
{
	this->name = ob.name;
	this->hitPoint = ob.hitPoint;
	this->energyPoint = ob.energyPoint;
	this->attackDamage = ob.attackDamage;

	std::cout << "ClapTrap " << this->name << " assignation constructor called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hitPoint || !this->energyPoint)
		std::cout << "ClapTrap " << this->name << " can't do anything..." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target \
			<< " ,causing " << this->attackDamage << " points of demage!" << std::endl;
		this->energyPoint--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoint -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" \
		<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoint || !this->energyPoint)
		std::cout << "ClapTrap " << this->name << " can't do anything..." << std::endl;
	else
	{
		this->hitPoint += amount;
		std::cout << "ClapTrap " << this->name << " repairs " << amount << " itself!" \
		<< " It has " << this->hitPoint << " Hitpoint" << std::endl;
	}
}	
