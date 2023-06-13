/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:29:02 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 15:32:31 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
int main()
{
	Animal *a = new Dog();
	Animal *b = new Cat();

	a->makeSound();
	b->makeSound();
	delete a;
	delete b;
	return 0;
}