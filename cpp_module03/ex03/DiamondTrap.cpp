/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:00:55 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/21 14:23:26 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name(ClapTrap::name)
{
	ClapTrap::name = name + "_clap_name";
	this->attackDamage = 30;
	std::cout << "DiamondTrap default construct called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : name(name)
{
	ClapTrap::name = name + "_clap_name";
	this->attackDamage = 30;
	std::cout << "DiamondTrap " << name << " construct called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &ob) : ClapTrap(ob), FragTrap(ob), ScavTrap(ob), name(ob.name)
{
	std::cout << "DiamondTrap " << this->name << " copy construct called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &ob)
{
	if (this != &ob)
	{
		this->name = ob.name;
		ClapTrap::name = ob.name + "_clap_name";
		this->hitPoint = ob.hitPoint;
		this->energyPoint = ob.energyPoint;
		this->attackDamage = ob.attackDamage;
	}
	std::cout << "DiamondTrap " << this->name << " assignation construct called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destruct called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "this ClapTrap name is " << ClapTrap::name << " and " \
		<< "this DiamondTrap name is " << this->name << std::endl;
}

void DiamondTrap::printStatus(void)
{
	std::cout	<< "This DiamondTrap name is " << this->name << "\n"
				<< "HitPoint is " << hitPoint << "\n"
				<< "EnergyPoint is " << energyPoint << "\n"
				<< "AttackDamage is " << attackDamage << "\n"
				<< "ClapTrap Name is " << ClapTrap::name << std::endl;
}