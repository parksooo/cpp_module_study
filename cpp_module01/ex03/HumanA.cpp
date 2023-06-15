/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:03 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 16:52:38 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
    std::cout << "HumanA " << name << " constuctor called" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "Human A destructor called" << std::endl;
}

void    HumanA::attack() const
{
    std::cout << this->name << " attacks with his " << weapon.getType() << std::endl;
}
