/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:34:20 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/03 20:37:24 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
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
