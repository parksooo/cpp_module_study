/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:34:20 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 16:47:33 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie default constructor called" << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie " << name << " constructor called" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is DEAD" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << this->name << "> " << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}