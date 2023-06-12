/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:02 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 19:23:58 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	Animal *horde[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 != 0)
			horde[i] = new Cat();
		else
			horde[i] = new Dog();
	}

	for (int i = 0; i < 10; i++)
		horde[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete horde[i];
	std::cout << std::endl;
	
	Dog *a = new Dog();
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		std::cout << a->getBrain()->getIdea(i) << " ";
	std::cout << std::endl;
	a->getBrain()->setIdea("OH excited!", 5);
	for (int i = 0; i < 6; i++)
		std::cout << a->getBrain()->getIdea(i) << " ";
	std::cout << std::endl;
	
	return 0;
}