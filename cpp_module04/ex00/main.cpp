/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:02 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 17:30:47 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << meta->getType() << " " << std:: endl;
	meta->makeSound();

	std::cout << std::endl;
	delete j;
	delete i;
	delete meta;
	
	std::cout << std::endl;
	
	const WrongAnimal *a = new WrongAnimal();
	const WrongAnimal *b = new WrongCat();
	
	std::cout << a->getType() << " " << std::endl;
	a->makeSound();
	std::cout << b->getType() << " " << std::endl;
	b->makeSound();
	std::cout << std::endl;
	delete a;
	delete b;
	std::cout << std::endl;
	return 0;
}