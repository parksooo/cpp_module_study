/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:53:49 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/26 14:40:54 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal{
	protected	:
				std::string type;
	public		:
				Animal();
				Animal(Animal const &ob);
				Animal& operator=(Animal const &ob);
				virtual ~Animal();
				virtual void	makeSound() const;
				std::string	getType() const;
};
#endif