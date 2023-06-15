/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:02 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 15:33:02 by suhwpark         ###   ########.fr       */
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
	delete a;
	
	std::cout << std::endl;

	Cat *b = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		std::cout << b->getBrain()->getIdea(i) << " ";
	std::cout << std::endl;
	b->getBrain()->setIdea("OH excited!", 1);
	b->getBrain()->setIdea("So FUCKIN DAY..", 3);
	for (int i = 0; i < 6; i++)
		std::cout << b->getBrain()->getIdea(i) << " ";
	std::cout << std::endl;
	delete b;
	return 0;
}