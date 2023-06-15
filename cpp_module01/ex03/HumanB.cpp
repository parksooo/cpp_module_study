/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:07 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 16:53:49 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    std::cout << "Human B " << name << " constructor called" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "Human B destructor called" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack() const
{
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}