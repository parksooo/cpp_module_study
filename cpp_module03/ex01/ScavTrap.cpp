/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:22:29 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/11 15:43:26 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "default";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;

	std::cout << "Scavtrap default construct called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;

	std::cout << "Scavtrap " << name << " default construct called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ob)
{
	this->name = ob.name;
	this->hitPoint = ob.hitPoint;
	this->energyPoint = ob.energyPoint;
	this->attackDamage = ob.attackDamage;

	std::cout << "Scavtrap " << this->name << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ob)
{
	this->name = ob.name;
	this->hitPoint = ob.hitPoint;
	this->energyPoint = ob.energyPoint;
	this->attackDamage = ob.attackDamage;

	std::cout << "Scavtrap " << this->name << " assignation constructor called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->hitPoint || !this->energyPoint)
		std::cout << "Scavtrap " << this->name << " can't do anything..." << std::endl;
	else
	{
		std::cout << "Scavtrap " << this->name << " attacks " << target \
			<< " ,causing " << this->attackDamage << " points of demage!" << std::endl;
		this->energyPoint--;
	}
}

void ScavTrap::guardGate()
{
	if (!this->hitPoint || !this->energyPoint)
		std::cout << "Scavtrap " << this->name << " can't do anything..." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " started gate guarg mode !" << std::endl;
		this->energyPoint--;
	}
}
