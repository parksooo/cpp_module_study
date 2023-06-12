/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:17:27 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 19:22:05 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &ob)
{
	this->type = ob.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &ob)
{
	if (this != &ob)
		this->type = ob.type;

	std::cout << "Dog assignation constructor called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bowwow...!!" << std::endl;
}
