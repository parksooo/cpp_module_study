/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:59:31 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 15:21:02 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &ob)
{
	this->type = ob.type;

	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &ob)
{
	if (this != &ob)
		this->type = ob.type;
	std::cout << "Animal assignation constructor called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
