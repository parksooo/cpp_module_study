/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:14 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 16:54:46 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    std::cout << "Weapon " << type << " constructor called" << std::endl;
    this->type = type;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destructor called" << std::endl;
}

std::string Weapon::getType() const
{
    return this->type;
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}