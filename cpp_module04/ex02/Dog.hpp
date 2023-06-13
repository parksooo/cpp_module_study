/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:07:49 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 19:19:55 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
	private	:
			Brain *brain;
	public	:
			Dog();
			Dog(Dog const &ob);
			Dog& operator=(Dog const &ob);
			~Dog();
			void	makeSound() const;
			Brain*	getBrain() const;
};
#endif