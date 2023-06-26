/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:56:46 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/26 14:47:21 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain defualt constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->idea[i] = "So Bored...";
}

Brain::Brain(Brain const &ob)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = ob;
}

Brain &Brain::operator=(Brain const &ob)
{
	std::cout << "Brain Assignation constructor called" << std::endl;
	if (this != &ob)
	{
		for (int i = 0; i < 100; i++)
			this->idea[i] = ob.getIdea(i);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int n) const
{
	return this->idea[n];
}

void Brain::setIdea(std::string think, int n)
{
	this->idea[n] = think;
}
