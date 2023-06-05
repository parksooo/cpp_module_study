/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:03 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:03 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void    HumanA::attack() const
{
    std::cout << this->name << " attacks with his " << weapon.getType() << std::endl;
}
